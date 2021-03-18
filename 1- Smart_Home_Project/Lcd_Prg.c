/*
 * Lcd_Prg.c
 *
 *  Created on: Jan 31, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/Bit_math.h"
#include"Lcd_int.h"
#include"Dio_int.h"
#include"Lcd_cfg.h"
#include"Lcd_int.h"
#define F_CPU 8000000
#include<util/delay.h>


void Lcd_vidSendCommand(u8 Cmd)
{

	Dio_vidSetPinVal(LCD_u8RW_PIN,DIO_u8LOW); //RS
	Dio_vidSetPinVal(LCD_u8RS_PIN,DIO_u8LOW); //RS

	//	PORTD=Cmd;
	Dio_vidSetPinVal(LCD_u8D0_PIN , GET_BIT(Cmd,0));
	Dio_vidSetPinVal(LCD_u8D1_PIN , GET_BIT(Cmd,1));
	Dio_vidSetPinVal(LCD_u8D2_PIN , GET_BIT(Cmd,2));
	Dio_vidSetPinVal(LCD_u8D3_PIN , GET_BIT(Cmd,3));
	Dio_vidSetPinVal(LCD_u8D4_PIN , GET_BIT(Cmd,4));
	Dio_vidSetPinVal(LCD_u8D5_PIN , GET_BIT(Cmd,5));
	Dio_vidSetPinVal(LCD_u8D6_PIN , GET_BIT(Cmd,6));
	Dio_vidSetPinVal(LCD_u8D7_PIN , GET_BIT(Cmd,7));

	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8HIGH); // EN
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8LOW); // EN

}


void Lcd_vidWriteChar(u8 Char)
{
	Dio_vidSetPinVal(LCD_u8RW_PIN,DIO_u8LOW); //RS
	Dio_vidSetPinVal(LCD_u8RS_PIN,DIO_u8HIGH); //RS

	//	PORTD=Cmd;
	Dio_vidSetPinVal(LCD_u8D0_PIN , GET_BIT(Char,0));
	Dio_vidSetPinVal(LCD_u8D1_PIN , GET_BIT(Char,1));
	Dio_vidSetPinVal(LCD_u8D2_PIN , GET_BIT(Char,2));
	Dio_vidSetPinVal(LCD_u8D3_PIN , GET_BIT(Char,3));
	Dio_vidSetPinVal(LCD_u8D4_PIN , GET_BIT(Char,4));
	Dio_vidSetPinVal(LCD_u8D5_PIN , GET_BIT(Char,5));
	Dio_vidSetPinVal(LCD_u8D6_PIN , GET_BIT(Char,6));
	Dio_vidSetPinVal(LCD_u8D7_PIN , GET_BIT(Char,7));

	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8HIGH); // EN
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8LOW); // EN


}


void Lcd_vidINIT(void)
{
	//DDRD=0xFF;
	Dio_vidSetPinDir(LCD_u8D0_PIN ,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D1_PIN ,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D2_PIN ,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D3_PIN ,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D4_PIN ,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D5_PIN ,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D6_PIN ,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D7_PIN ,DIO_u8OUTPUT);

	Dio_vidSetPinDir(LCD_u8RS_PIN ,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RW_PIN ,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8EN_PIN ,DIO_u8OUTPUT);


	//DDRA=0xFF;
	Lcd_vidSendCommand(LCD_u8CMD_8_BIT_2x16_5x7);
	_delay_ms(2);
	Lcd_vidSendCommand(LCD_u8CMD_DISP_ON_CURS_OFF);
	_delay_ms(2);
	Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
	_delay_ms(2);

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
