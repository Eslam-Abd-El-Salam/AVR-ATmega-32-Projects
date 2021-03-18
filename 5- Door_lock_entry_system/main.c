/*
 * main.c
 *
 *  Created on: Feb 15, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Dio_int.h"
#include"Keypad_int.h"
#include"Lcd_int.h"
#include"Stepper_int.h"
#include"Led_int.h"
#undef F_CPU
#define F_CPU 8000000
#include<util/delay.h>

int main(void)
{


	u8 i,index,key,flag_1;
	u16 Sum;
	u8 arr[4]={0};
	index=0;
	flag_1=0;

	Lcd_vidINIT();
	Keypad_vidInit();
	Led_vidInit(1);
	Stepper_vidInit();

	for(i=0;i<2;i++)
	{
		Lcd_vidSendCommand(0x84);
		Lcd_vidWriteChar('W');
		Lcd_vidWriteChar('e');
		Lcd_vidWriteChar('l');
		Lcd_vidWriteChar('c');
		Lcd_vidWriteChar('o');
		Lcd_vidWriteChar('m');
		Lcd_vidWriteChar('e');
		Lcd_vidSendCommand(0xC5);
		Lcd_vidWriteChar('D');
		Lcd_vidWriteChar('u');
		Lcd_vidWriteChar('d');
		Lcd_vidWriteChar('e');
		Lcd_vidWriteChar('!');
		_delay_ms(1000);
		Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
		_delay_ms(400);

	}
	Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);

	Lcd_vidSendCommand(0x80);
	Lcd_vidSendCommand(0x0F);
	Lcd_vidWriteChar('U');
	Lcd_vidWriteChar('s');
	Lcd_vidWriteChar('e');
	Lcd_vidWriteChar('r');
	Lcd_vidWriteChar('I');
	Lcd_vidWriteChar('D');
	Lcd_vidWriteChar(':');
	Lcd_vidSendCommand(0xC0);
	Lcd_vidWriteChar('P');
	Lcd_vidWriteChar('a');
	Lcd_vidWriteChar('s');
	Lcd_vidWriteChar('s');
	Lcd_vidWriteChar('W');
	Lcd_vidWriteChar('o');
	Lcd_vidWriteChar('r');
	Lcd_vidWriteChar('d');
	Lcd_vidWriteChar(':');

	Enter_ID_Again:
	Lcd_vidSendCommand(0x87);

	again:
	for(;;)
	{
		key=Keypad_GetKey();
		if(key!= 0xFF)
			break;
	}

	Lcd_vidWriteChar(key+0x30);
	_delay_ms(500);
	arr[index]=key;
	index++;
	if (index!=4)
		goto again;
	Sum=(arr[3]+arr[2]*10+arr[1]*100+arr[0]*1000);
	for(;;)
	{
		key=Keypad_GetKey();
		if((key!= 0xFF) && (key>9))
			break;
	}
	_delay_ms(400);
	if (Sum!=1822)
	{
		Lcd_vidSendCommand(0x87);
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
			Lcd_vidSendCommand(0x87);
			Lcd_vidWriteChar(' ');
			Lcd_vidWriteChar(' ');
			Lcd_vidWriteChar(' ');
			Lcd_vidWriteChar(' ');
			Lcd_vidWriteChar(' ');
			Lcd_vidWriteChar(' ');
			goto Enter_ID_Again;
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
			_delay_ms(400);
			Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
			Led_vidTurnOff(1);
			_delay_ms(400);

		}
	}

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
	_delay_ms(500);
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
			_delay_ms(400);
			Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
			Led_vidTurnOff(1);
			_delay_ms(400);

		}
	}

	Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
	Lcd_vidWriteChar('O');
	Lcd_vidWriteChar('p');
	Lcd_vidWriteChar('e');
	Lcd_vidWriteChar('n');
	Lcd_vidWriteChar('i');
	Lcd_vidWriteChar('n');
	Lcd_vidWriteChar('g');
	Lcd_vidWriteChar('.');
	Lcd_vidWriteChar('.');
	Lcd_vidWriteChar('.');
	Stepper_TurnLeft(180);
	_delay_ms(1000);
	Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
	Lcd_vidWriteChar('C');
	Lcd_vidWriteChar('l');
	Lcd_vidWriteChar('o');
	Lcd_vidWriteChar('s');
	Lcd_vidWriteChar('i');
	Lcd_vidWriteChar('n');
	Lcd_vidWriteChar('g');
	Lcd_vidWriteChar('.');
	Lcd_vidWriteChar('.');
	Lcd_vidWriteChar('.');

	Stepper_TurnRight(180);
	_delay_ms(1000);
	Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
	while(1)
	{
	}

	return 0;


}

