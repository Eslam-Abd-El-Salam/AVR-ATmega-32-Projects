/*
 * main.c
 *
 *  Created on: Jan 31, 2020
 *      Author: eslam
 */
#include<avr/io.h>
#include"../Lib/datatype.h"
#include"../Lib/Bit_math.h"
#include"Lcd_int.h"
#define F_CPU 8000000
#include<util/delay.h>

u8 i;
void forward();
void reverse();
int main (void)
{

	Lcd_vidINIT();

	while(1)
	{

		forward();
		Lcd_vidSendCommand(0x01); //Clear
		Lcd_vidSendCommand(0xc0);  //2line
		forward();
		reverse();
		Lcd_vidSendCommand(0x8F);
		Lcd_vidWriteChar('X');
		_delay_ms(100);
		reverse();

		/*for (i=0;i<15;i++)
         {
	        Lcd_vidWriteChar(' ');
         }
            Lcd_vidWriteChar('X');
            _delay_ms(100);*/

	}


	return (0);

}

void forward()
{
	Lcd_vidWriteChar('X');
	_delay_ms(200);

	for(i=0;i<15;i++)
	{
		Lcd_vidSendCommand(0x1c);
		_delay_ms(200);
	}
}

void reverse()
{


	for(i=0;i<15;i++)
	{
		Lcd_vidSendCommand(0x18);
		_delay_ms(200);
	}
}
