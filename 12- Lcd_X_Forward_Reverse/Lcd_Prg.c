/*
 * Lcd_Prg.c
 *
 *  Created on: Jan 31, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/Bit_math.h"
#include"Lcd_int.h"
#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>


void Lcd_vidSendCommand(u8 Cmd)
{
	CLR_BIT(PORTA,1); //RW
	CLR_BIT(PORTA,0); //RS
	PORTD=Cmd;
	SET_BIT(PORTA,2); // EN
	_delay_ms(2);
	CLR_BIT(PORTA,2); //EN

}


void Lcd_vidWriteChar(u8 Char)
{
	CLR_BIT(PORTA,0); //RS
	SET_BIT(PORTA,0);
	PORTD=Char;
	SET_BIT(PORTA,2); // EN
	_delay_ms(2);
	CLR_BIT(PORTA,2); //EN

}


void Lcd_vidINIT(void)
{
	DDRD=0xFF;
	DDRA=0xFF;
	Lcd_vidSendCommand(0x38);
	_delay_ms(2);
	Lcd_vidSendCommand(0x0c);
	_delay_ms(2);
	Lcd_vidSendCommand(0x01);
	_delay_ms(2);

}
