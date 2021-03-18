/*
 * main.c
 *
 *  Created on: Mar 6, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Dio_int.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#include"Lcd_int.h"
#define F_CPU 8000000
#include<util/delay.h>
u8 first_reading=0;
f32 Ton,Distance;
u32 ovf_counts;


int main(void)
{

	CLR_BIT(TCCR1A,1);    //Wave form Generation Mode Normal Mode
	CLR_BIT(TCCR1A,0);    //Wave form Generation Mode Normal Mode
	CLR_BIT(TCCR1B,4);    //Wave form Generation Mode Normal Mode
	CLR_BIT(TCCR1B,3);    //Wave form Generation Mode Normal Mode


	CLR_BIT(TCCR1B,7);    //input capture noise canceller
	SET_BIT(TCCR1B,6);    //input capture on rising edge



	SET_BIT(TIMSK,5);     //Input Capture interrupt Enable
	SET_BIT(TIMSK,2);     //Input Capture overFlow interrupt Enable

	SET_BIT(SREG,7);      //Global interrupt

	Dio_vidSetPinDir(DIO_u8PIN_30,DIO_u8INPUT);
	Dio_vidSetPinDir(DIO_u8PIN_24,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_31,DIO_u8OUTPUT);

	CLR_BIT(TCCR1B,2);     //No Presacling
	CLR_BIT(TCCR1B,1);     //No Presacling
	SET_BIT(TCCR1B,0);     //No Presacling

	Lcd_vidINIT();
	while(1)
	{
		Dio_vidSetPinVal(DIO_u8PIN_24,DIO_u8HIGH);
		_delay_ms(10);
		Dio_vidSetPinVal(DIO_u8PIN_24,DIO_u8LOW);


		Distance=((Ton*(u32)34300)/(f32)2);


		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('D');
		Lcd_vidWriteChar('I');
		Lcd_vidWriteChar('S');
		Lcd_vidWriteChar('T');
		Lcd_vidWriteChar('A');
		Lcd_vidWriteChar('N');
		Lcd_vidWriteChar('C');
		Lcd_vidWriteChar('E');
		Lcd_vidWriteChar('=');

		Lcd_vidWriteChar(((u8)Distance/100)+'0');
		Lcd_vidWriteChar((((u8)Distance%100)/10)+'0');
		Lcd_vidWriteChar(((u8)Distance%10)+'0');
		/*Lcd_vidWriteChar(((u8)Distance/10)+'0');
		Lcd_vidWriteChar(((u8)Distance%10)+'0');*/

if (((u8)Distance <=20)&&((u8)Distance >=10))
	Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8HIGH);
else
	Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8LOW);
	}
	return 0;


}


ISR(TIMER1_OVF_vect)
{
	ovf_counts++;
}

ISR(TIMER1_CAPT_vect)
{
	if (first_reading==0)
	{
		TCNT1=0;
		ovf_counts=0;
		first_reading=1;
		CLR_BIT(TCCR1B,6);   //input capture on Falling edge for next time to start calculations


	}
	else
	{
		//Calculte Ton

		TCNT1=0;
		SET_BIT(TCCR1B,6);    //input capture on rising edge for next time
		Ton=(f32)(ICR1+(65536*ovf_counts)/*Total number of counts*/ )/(f32)8000000;
		ovf_counts=0;
		first_reading=0;


	}
}
