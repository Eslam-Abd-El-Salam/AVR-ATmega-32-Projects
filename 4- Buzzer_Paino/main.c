/*
 * main.c
 *
 *  Created on: Feb 29, 2020
 *      Author: eslam
 */

#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Dio_int.h"
#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>

int main(void)
{

	Dio_vidSetPinDir(DIO_u8PIN_29,DIO_u8OUTPUT);
	SET_BIT(TCCR1A,7);  //A1  Select Channel A on compare mode1 Clear OC1A/OC1B on compare match, set OC1A/OC1B at TOP
	SET_BIT(TCCR1A,6);  //A0
	SET_BIT(TCCR1A,1);  //Wave Generation  Mode FPWM
	CLR_BIT(TCCR1A,0);  //Wave Generation  Mode FPWM
	SET_BIT(TCCR1B,4);  //Wave Generation  Mode FPWM
	SET_BIT(TCCR1B,3);  //Wave Generation  Mode FPWM

	CLR_BIT(TCCR1B,2);
	CLR_BIT(TCCR1B,1);      //Clock select
	SET_BIT(TCCR1B,0);

	while(1)
	{



		ICR1=30534;             //Hap 262
		OCR1A=15267;
		_delay_ms(100);

		ICR1=0;
		OCR1A=0;

		_delay_ms(100);
		ICR1=30534;            //py  262
		OCR1A=15267;

		_delay_ms(150);

		ICR1=0;
		OCR1A=0;
		_delay_ms(100);

		ICR1=27210;            //Birth  D4   294
		OCR1A=13605;
		_delay_ms(300);
		ICR1=0;
		OCR1A=0;
		_delay_ms(100);

		ICR1=30534;             //Day   C4   262
		OCR1A=15267;
		_delay_ms(300);

		ICR1=22922;             //To   F4 349
		OCR1A=11461;
		_delay_ms(300);

		ICR1=24242;             //you   E4 330
		OCR1A=12121;
		_delay_ms(300);

		ICR1=0;
		OCR1A=0;
		_delay_ms(500);

		/*************************************************/

		ICR1=30534;             //Hap 262
		OCR1A=15267;
		_delay_ms(100);

		ICR1=0;
		OCR1A=0;

		_delay_ms(100);
		ICR1=30534;            //py  262
		OCR1A=15267;

		_delay_ms(150);

		ICR1=0;
		OCR1A=0;
		_delay_ms(100);

		ICR1=27210;            //Birth  D4   294
		OCR1A=13605;
		_delay_ms(300);
		ICR1=0;
		OCR1A=0;
		_delay_ms(100);

		ICR1=30534;             //Day   C4   262
		OCR1A=15267;
		_delay_ms(300);

		ICR1=20408;             //To   G4   392
		OCR1A=10204;
		_delay_ms(300);

		ICR1=22922;             //you   F4  349
		OCR1A=11461;
		_delay_ms(300);

		ICR1=0;
		OCR1A=0;
		_delay_ms(500);

		/**********************************************/



		ICR1=30534;             //Hap 262
		OCR1A=15267;
		_delay_ms(100);

		ICR1=0;
		OCR1A=0;

		_delay_ms(100);
		ICR1=30534;            //py  262
		OCR1A=15267;

		_delay_ms(150);

		ICR1=0;
		OCR1A=0;
		_delay_ms(100);

		ICR1=15296;            //Birth  C5 523
		OCR1A=7648;
		_delay_ms(300);
		ICR1=0;
		OCR1A=0;
		_delay_ms(100);

		ICR1=18181;             //Day   A4  440   about
		OCR1A=9091;
		_delay_ms(300);

		ICR1=22922;             //Dear   F4   349
		OCR1A=11461;
		_delay_ms(300);

		ICR1=24242;             //XXXX   E4  330
		OCR1A=12121;
		_delay_ms(300);
		ICR1=0;
		OCR1A=0;
		_delay_ms(500);
		/*****************************************************/

		ICR1=17167;             //Hap B4b 466
		OCR1A=8584;
		_delay_ms(100);

		ICR1=0;
		OCR1A=0;

		_delay_ms(100);
		ICR1=17167;            //py  B4b 466
		OCR1A=8584;

		_delay_ms(150);

		ICR1=0;
		OCR1A=0;
		_delay_ms(100);

		ICR1=18181;            //Birth  A4
		OCR1A=9091;
		_delay_ms(300);
		ICR1=0;
		OCR1A=0;
		_delay_ms(100);

		ICR1=22922;             //Day   F4
		OCR1A=11461;
		_delay_ms(300);

		ICR1=20408;             //To   G4
		OCR1A=10204;
		_delay_ms(300);

		ICR1=22922;             //You   F4
		OCR1A=11461;
		_delay_ms(300);
		ICR1=0;
		OCR1A=0;
		_delay_ms(500);



		/*****************************************************/


	}
	return 0;


}
