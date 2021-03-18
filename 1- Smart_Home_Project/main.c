/*
 * main.c
 *
 *  Created on: Mar 2, 2020
 *      Author: eslam
 */

#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Keypad_int.h"
#include"Lcd_int.h"
#include"Stepper_int.h"
#include"Led_int.h"
#include"Buzzer_int.h"
#include"DCM_int.h"
#include"Servo_int.h"


#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>

void Welcome(u8 position,u8 Chr);
void Heart_Custom();
void Fan();

u8 i,x,key;
u8 index_1=0;
int main(void)
{

	u8 index,flag_1;
	u16 Sum;
	u8 arr[4]={0};
	index=0;
	flag_1=0;

	Lcd_vidINIT();
	Keypad_vidInit();
	Led_vidInit(1);
	Buzz_vidInit();
	Stepper_INIT();
	DcMotor_vidInit();
	Servo_vidInit(2);



	Heart_Custom();

	Start_Again:
	Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
	Welcome(11,0x00);
	Welcome(10,'e');
	Welcome(9,'m');
	Welcome(8,'o');
	Welcome(7,'c');
	Welcome(6,'l');
	Welcome(5,'e');
	Welcome(4,'W');
	_delay_ms(500);
	for (i=0;i<2;i++)
	{
		Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
		_delay_ms(1000);
		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar('W');
		Lcd_vidWriteChar('e');
		Lcd_vidWriteChar('l');
		Lcd_vidWriteChar('c');
		Lcd_vidWriteChar('o');
		Lcd_vidWriteChar('m');
		Lcd_vidWriteChar('e');
		Lcd_vidWriteChar(0x00);
		_delay_ms(1000);

	}

	Lcd_vidSendCommand(0xC0);
	Lcd_vidSendCommand(0x0F);
	Lcd_vidWriteChar('P');
	Lcd_vidWriteChar('a');
	Lcd_vidWriteChar('s');
	Lcd_vidWriteChar('s');
	Lcd_vidWriteChar('W');
	Lcd_vidWriteChar('o');
	Lcd_vidWriteChar('r');
	Lcd_vidWriteChar('d');
	Lcd_vidWriteChar(':');




	Enter_Password_Again:
	index=0;
	Sum=0;

	Lcd_vidSendCommand(0xC9);

	again_Password:
	for(;;)
	{
		key=Keypad_GetKey();
		if(key!= 0xFF)
			break;
	}

	Lcd_vidWriteChar(key+0x30);
	_delay_ms(200);
	if(index==0)
		Lcd_vidSendCommand(0xC9);
	if(index==1)
		Lcd_vidSendCommand(0xCA);
	if(index==2)
		Lcd_vidSendCommand(0xCB);
	if(index==3)
		Lcd_vidSendCommand(0xCC);

	Lcd_vidWriteChar('*');

	arr[index]=key;
	index++;
	if (index!=4)
		goto again_Password;
	Sum=(arr[3]+arr[2]*10+arr[1]*100+arr[0]*1000);
	for(;;)
	{
		key=Keypad_GetKey();
		if((key!= 0xFF) && (key>9))
			break;
	}
	_delay_ms(400);
	if (Sum!=1234)
	{
		Lcd_vidSendCommand(0xC9);
		Lcd_vidWriteChar('W');
		Lcd_vidWriteChar('r');
		Lcd_vidWriteChar('o');
		Lcd_vidWriteChar('n');
		Lcd_vidWriteChar('g');
		Lcd_vidWriteChar((flag_1+1)+0x30);
		_delay_ms(1000);
		flag_1++;

		while(flag_1!=3)
		{
			index=0;
			arr[0]=0;
			arr[1]=0;
			arr[2]=0;
			arr[3]=0;
			Lcd_vidSendCommand(0xC9);
			Lcd_vidWriteChar(' ');
			Lcd_vidWriteChar(' ');
			Lcd_vidWriteChar(' ');
			Lcd_vidWriteChar(' ');
			Lcd_vidWriteChar(' ');
			Lcd_vidWriteChar(' ');
			goto Enter_Password_Again;
		}


		Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
		Lcd_vidSendCommand(0x0C);

		for(;;)
		{
			Lcd_vidSendCommand(0x85);

			Lcd_vidWriteChar('B');
			Lcd_vidWriteChar('L');
			Lcd_vidWriteChar('o');
			Lcd_vidWriteChar('c');
			Lcd_vidWriteChar('k');
			Lcd_vidWriteChar('e');
			Lcd_vidWriteChar('d');

			Lcd_vidSendCommand(0xC5);
			Lcd_vidWriteChar('T');
			Lcd_vidWriteChar('h');
			Lcd_vidWriteChar('i');
			Lcd_vidWriteChar('e');
			Lcd_vidWriteChar('f');
			Lcd_vidWriteChar('!');
			Lcd_vidWriteChar('!');
			Led_vidTurnOn(1);
			Buzz_vidTurnOn();
			_delay_ms(400);
			Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
			Led_vidTurnOff(1);
			Buzz_vidTurnOff();
			_delay_ms(400);

		}
	}

	Lcd_vidSendCommand(0x0C);
	Lcd_vidSendCommand(0x81);
	Lcd_vidWriteChar(0x00);
	Lcd_vidWriteChar('W');
	Lcd_vidWriteChar('e');
	Lcd_vidWriteChar('l');
	Lcd_vidWriteChar('c');
	Lcd_vidWriteChar('o');
	Lcd_vidWriteChar('m');
	Lcd_vidWriteChar('e');
	Lcd_vidWriteChar('H');
	Lcd_vidWriteChar('o');
	Lcd_vidWriteChar('m');
	Lcd_vidWriteChar('e');
	Lcd_vidWriteChar(0x00);

	Lcd_vidSendCommand(0xC0);
	Lcd_vidWriteChar('D');
	Lcd_vidWriteChar('O');
	Lcd_vidWriteChar('O');
	Lcd_vidWriteChar('R');
	Lcd_vidWriteChar('O');
	Lcd_vidWriteChar('P');
	Lcd_vidWriteChar('E');
	Lcd_vidWriteChar('N');
	Lcd_vidWriteChar('I');
	Lcd_vidWriteChar('N');
	Lcd_vidWriteChar('G');
	Lcd_vidWriteChar('.');
	Lcd_vidWriteChar('.');
	Lcd_vidWriteChar('.');


	Stepper_TurnLeft(180);
	_delay_ms(1000);
	Lcd_vidSendCommand(0xC0);
	Lcd_vidWriteChar('D');
	Lcd_vidWriteChar('O');
	Lcd_vidWriteChar('O');
	Lcd_vidWriteChar('R');
	Lcd_vidWriteChar('C');
	Lcd_vidWriteChar('L');
	Lcd_vidWriteChar('O');
	Lcd_vidWriteChar('S');
	Lcd_vidWriteChar('I');
	Lcd_vidWriteChar('N');
	Lcd_vidWriteChar('G');
	Lcd_vidWriteChar('.');
	Lcd_vidWriteChar('.');
	Lcd_vidWriteChar('.');
	Stepper_TurnRight(180);
	Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);

	Lcd_vidSendCommand(0x85);
	Lcd_vidWriteChar('L');
	Lcd_vidWriteChar('o');
	Lcd_vidWriteChar('a');
	Lcd_vidWriteChar('d');
	Lcd_vidWriteChar('i');
	Lcd_vidWriteChar('n');
	Lcd_vidWriteChar('g');
	Lcd_vidSendCommand(0xCA);
	Lcd_vidWriteChar('S');
	Lcd_vidWriteChar('y');
	Lcd_vidWriteChar('s');
	Lcd_vidWriteChar('t');
	Lcd_vidWriteChar('e');
	Lcd_vidWriteChar('m');


	for(i=0;i<=5;i++)
	{
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar(0x01);
		_delay_ms(200);
		Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
		Lcd_vidSendCommand(0x85);
		Lcd_vidWriteChar('L');
		Lcd_vidWriteChar('o');
		Lcd_vidWriteChar('a');
		Lcd_vidWriteChar('d');
		Lcd_vidWriteChar('i');
		Lcd_vidWriteChar('n');
		Lcd_vidWriteChar('g');
		Lcd_vidSendCommand(0xCA);
		Lcd_vidWriteChar('S');
		Lcd_vidWriteChar('y');
		Lcd_vidWriteChar('s');
		Lcd_vidWriteChar('t');
		Lcd_vidWriteChar('e');
		Lcd_vidWriteChar('m');
		Lcd_vidSendCommand(0xc2);
		Lcd_vidWriteChar(0x03);
		_delay_ms(200);
		Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
		Lcd_vidSendCommand(0x85);
		Lcd_vidWriteChar('L');
		Lcd_vidWriteChar('o');
		Lcd_vidWriteChar('a');
		Lcd_vidWriteChar('d');
		Lcd_vidWriteChar('i');
		Lcd_vidWriteChar('n');
		Lcd_vidWriteChar('g');
		Lcd_vidSendCommand(0xCA);
		Lcd_vidWriteChar('S');
		Lcd_vidWriteChar('y');
		Lcd_vidWriteChar('s');
		Lcd_vidWriteChar('t');
		Lcd_vidWriteChar('e');
		Lcd_vidWriteChar('m');
		Lcd_vidSendCommand(0xc1);
		Lcd_vidWriteChar(0x04);
		_delay_ms(200);
		Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
		Lcd_vidSendCommand(0x85);
		Lcd_vidWriteChar('L');
		Lcd_vidWriteChar('o');
		Lcd_vidWriteChar('a');
		Lcd_vidWriteChar('d');
		Lcd_vidWriteChar('i');
		Lcd_vidWriteChar('n');
		Lcd_vidWriteChar('g');
		Lcd_vidSendCommand(0xCA);
		Lcd_vidWriteChar('S');
		Lcd_vidWriteChar('y');
		Lcd_vidWriteChar('s');
		Lcd_vidWriteChar('t');
		Lcd_vidWriteChar('e');
		Lcd_vidWriteChar('m');
		Lcd_vidSendCommand(0x81);
		Lcd_vidWriteChar(0x02);
		_delay_ms(200);
		Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
	}


	Again_opions:
	_delay_ms(300);
	Lcd_vidSendCommand(0x80);
	Lcd_vidWriteChar('1');
	Lcd_vidWriteChar('-');
	Lcd_vidWriteChar('W');
	Lcd_vidWriteChar('i');
	Lcd_vidWriteChar('n');
	Lcd_vidWriteChar('d');
	Lcd_vidWriteChar('o');
	Lcd_vidWriteChar('w');

	Lcd_vidSendCommand(0x8A);
	Lcd_vidWriteChar('2');
	Lcd_vidWriteChar('-');
	Lcd_vidWriteChar('F');
	Lcd_vidWriteChar('a');
	Lcd_vidWriteChar('n');

	Lcd_vidSendCommand(0xC0);

	Lcd_vidWriteChar('3');
	Lcd_vidWriteChar('-');
	Lcd_vidWriteChar('L');
	Lcd_vidWriteChar('e');
	Lcd_vidWriteChar('d');

	Lcd_vidSendCommand(0xCA);
	Lcd_vidWriteChar('4');
	Lcd_vidWriteChar('-');
	Lcd_vidWriteChar('E');
	Lcd_vidWriteChar('x');
	Lcd_vidWriteChar('i');
	Lcd_vidWriteChar('t');

	for(;;)
	{
		key=Keypad_GetKey();
		if(key!= 0xFF)
			break;
	}

	_delay_ms(300);
	switch(key)
	{
	case 1:



		break;

	case 2:

		Fan();
		goto Again_opions;

		break;


	case 3:


		Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
		Lcd_vidSendCommand(0x80);
		Lcd_vidWriteChar('3');
		Lcd_vidWriteChar('-');
		Lcd_vidWriteChar('L');
		Lcd_vidWriteChar('e');
		Lcd_vidWriteChar('d');
		Lcd_vidSendCommand(0xC0);

		/*do
			{
				key=Keypad_GetKey();

			}
          while(key==0xFF);*/
		LedIntensity_vidInit();
		LedIntensity_vidSetVal(150);
		goto Again_opions;

		break;


	case 4:

goto Start_Again;

		break;

		goto Again_opions;
	default:


		break;


	}





	return 0;


}


void Heart_Custom(void)
{
	Lcd_vidSendCommand(0x40);
	Lcd_vidWriteChar(0x00);
	Lcd_vidWriteChar(0x00);
	Lcd_vidWriteChar(0x0A);
	Lcd_vidWriteChar(0x15);
	Lcd_vidWriteChar(0x11);
	Lcd_vidWriteChar(0x0A);
	Lcd_vidWriteChar(0x04);
	Lcd_vidWriteChar(0x00);


	Lcd_vidSendCommand(0x48);
	Lcd_vidWriteChar(0x00);
	Lcd_vidWriteChar(0x10);
	Lcd_vidWriteChar(0x08);
	Lcd_vidWriteChar(0x04);
	Lcd_vidWriteChar(0x02);
	Lcd_vidWriteChar(0x02);
	Lcd_vidWriteChar(0x02);
	Lcd_vidWriteChar(0x02);

	Lcd_vidSendCommand(0x50);
	Lcd_vidWriteChar(0x00);
	Lcd_vidWriteChar(0x01);
	Lcd_vidWriteChar(0x02);
	Lcd_vidWriteChar(0x04);
	Lcd_vidWriteChar(0x10);
	Lcd_vidWriteChar(0x10);
	Lcd_vidWriteChar(0x10);
	Lcd_vidWriteChar(0x10);

	Lcd_vidSendCommand(0x58);
	Lcd_vidWriteChar(0x02);
	Lcd_vidWriteChar(0x02);
	Lcd_vidWriteChar(0x02);
	Lcd_vidWriteChar(0x02);
	Lcd_vidWriteChar(0x04);
	Lcd_vidWriteChar(0x08);
	Lcd_vidWriteChar(0x10);
	Lcd_vidWriteChar(0x00);

	Lcd_vidSendCommand(0x60);
	Lcd_vidWriteChar(0x10);
	Lcd_vidWriteChar(0x10);
	Lcd_vidWriteChar(0x10);
	Lcd_vidWriteChar(0x10);
	Lcd_vidWriteChar(0x04);
	Lcd_vidWriteChar(0x02);
	Lcd_vidWriteChar(0x01);
	Lcd_vidWriteChar(0x00);


}
void Welcome(u8 position,u8 Chr)
{
	for(i=0;i<=position;i++)
	{
		Lcd_vidSendCommand((0b10000000)+i);
		Lcd_vidWriteChar(Chr);
		_delay_ms(50);
		Lcd_vidSendCommand((0b10000000)+i);
		Lcd_vidWriteChar(' ');
		if(i==position)
		{
			Lcd_vidSendCommand((0b10000000)+i);
			Lcd_vidWriteChar(Chr);
		}
	}

}

void Fan()
{
	Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
	Lcd_vidSendCommand(0x80);
	Lcd_vidWriteChar('2');
	Lcd_vidWriteChar('-');
	Lcd_vidWriteChar('F');
	Lcd_vidWriteChar('a');
	Lcd_vidWriteChar('n');
	Lcd_vidSendCommand(0xc0);
	Lcd_vidWriteChar('1');
	Lcd_vidWriteChar('-');
	Lcd_vidWriteChar('O');
	Lcd_vidWriteChar('N');
	Lcd_vidSendCommand(0xCA);
	Lcd_vidWriteChar('2');
	Lcd_vidWriteChar('-');
	Lcd_vidWriteChar('O');
	Lcd_vidWriteChar('F');
	Lcd_vidWriteChar('F');
	for(;;)
	{
		key=Keypad_GetKey();
		if(key!= 0xFF)
			break;
	}

	if (key==1)
	{
		DcMotor_vidTurnOn();

	}

	if(key==2)
	{
		DcMotor_vidTurnOff();
	}

}
