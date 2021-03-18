/*
 * main.c
 *
 *  Created on: Jul 7, 2020
 *      Author: eslam
 */

#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Eeprom_int.h"
#include"I2c_int.h"
#include"Lcd_int.h"
#define F_CPU 8000000
#include<util/delay.h>
#include"Servo_int.h"
#include"Keypad_int.h"



u8 Eeprom_Block_Flag;
u8 Password[4];
u8 Password_Confirmation[4];
u8 Password_flag;
u8 Compare_Function_Flag;
u8 i;
u8 Recieve_Password;
u8 Compare_Array(u8 arr_1[],u8 arr_2[]);
void Custome_Loading(void);

int main (void)
{
	Servo_vidInit(1);
	Eeprom_vidInit();
	Lcd_vidInit();
	Custome_Loading();
	Keypad_vidInit();

	Eeprom_u8ReadByte(0,5,&Eeprom_Block_Flag);

	Lcd_vidSendCommand(0x85);
	Lcd_vidWriteString("Loading");
	Lcd_vidSendCommand(0xCA);
	Lcd_vidWriteString("System");




	for(i=0;i<=7;i++)
	{
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar(0x01);
		_delay_ms(100);
		Lcd_vidSendCommand(0x82);
		Lcd_vidWriteChar(' ');

		Lcd_vidSendCommand(0xc2);
		Lcd_vidWriteChar(0x03);
		_delay_ms(100);
		Lcd_vidSendCommand(0xc2);
		Lcd_vidWriteChar(' ');

		Lcd_vidSendCommand(0xc1);
		Lcd_vidWriteChar(0x04);
		_delay_ms(100);
		Lcd_vidSendCommand(0xc1);
		Lcd_vidWriteChar(' ');


		Lcd_vidSendCommand(0x81);
		Lcd_vidWriteChar(0x02);
		_delay_ms(100);
		Lcd_vidSendCommand(0x81);
		Lcd_vidWriteChar(' ');
	}
	Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);

	if (Eeprom_Block_Flag ==1)
	{
		Lcd_vidWriteString("System Is ");
		Lcd_vidSendCommand(0xC0);
		Lcd_vidWriteString("         Blocked");
		goto End;
	}

	Eeprom_u8ReadByte(0,0,&Recieve_Password);
	Password[0]=Recieve_Password;
	_delay_ms(10);
	Eeprom_u8ReadByte(0,1,&Recieve_Password);
	Password[1]=Recieve_Password;
	_delay_ms(10);
	Eeprom_u8ReadByte(0,2,&Recieve_Password);
	Password[2]=Recieve_Password;
	_delay_ms(10);
	Eeprom_u8ReadByte(0,3,&Recieve_Password);
	Password[3]=Recieve_Password;

	Lcd_vidWriteString("Enter Password: ");
	Lcd_vidSendCommand(0xC0);
	Try_Password_again:
	Password_flag++;

	if (Password_flag == 4)
	{
		Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
		Lcd_vidWriteString("System Is ");
		Lcd_vidSendCommand(0xC0);
		Lcd_vidWriteString("         Blocked");
		Eeprom_Block_Flag=1;
		Eeprom_u8WriteByte(0,5,1);
		goto End;
	}
	i=0;
	while(i != 4)
	{
		while( Keypad_GetKey() == 0xff);
		Password_Confirmation[i]= Keypad_GetKey()+0x30;
		_delay_ms(300);
		Lcd_vidWriteChar('*');
		i++;
	}

	Lcd_vidWriteChar(Compare_Array(Password,Password_Confirmation)+0x30);
	if (Compare_Array(Password,Password_Confirmation)== 0)
	{
		Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
		Lcd_vidWriteString("     Welcome");
		Servo_vidMoveServo(1,90);
		_delay_ms(1000);
		Servo_vidMoveServo(1,0);
	}

	else
	{
		Lcd_vidSendCommand(0xC0);
		Lcd_vidWriteString("Wrong Password");
		_delay_ms(1000);
		Lcd_vidSendCommand(0xC0);
		Lcd_vidWriteString("                ");
		Lcd_vidSendCommand(0xC0);
		goto Try_Password_again;
	}


	End:
	while(1);
	return 0;
}



u8 Compare_Array(u8 arr_1[],u8 arr_2[])
{
	u8 Compare_Flag;
	i=0;
	while(i != 4)
	{
		if (arr_1[i] != arr_2[i])
		{
			Compare_Flag=1;
			goto End;
		}
		else
			Compare_Flag=0;
		i++;
	}
	End:
	return Compare_Flag;

}


void Custome_Loading(void)
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
