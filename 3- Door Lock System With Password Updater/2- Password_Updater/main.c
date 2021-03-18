/*
 * main.c
 *
 *  Created on: Jul 7, 2020
 *      Author: eslam
 */

#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Eeprom_int.h"
#include"Uart_int.h"
#include"I2c_int.h"
#include"Lcd_int.h"
#define F_CPU 8000000
#include<util/delay.h>

#define PASSWORD_FLAG_FOUND       1
#define PASSWORD_FLAG_Not_FOUND   0
u8 Eeprom_Password_Flag;
u8 Password[4];
u8 Password_Confirmation[4];
u8 Password_Modify[4];
u8 Password_Modify_flag;
u8 Compare_Function_Flag;
u8 i;
u8 Recieve_Password;

void Password_New(u8 arr[]);
u8 Compare_Array(u8 arr_1[],u8 arr_2[]);

int main (void)
{

	Uart_vidInit();
	Eeprom_vidInit();
	Lcd_vidInit();


	Uart_vidSendByte('\r');
	Uart_vidSendString("                         Welcome To Password Updater                   ");

	Eeprom_u8WriteByte(0,5,0); //Disable Blocking System Of Door Locking


	Start_Again:
	Eeprom_u8ReadByte(0,4,&Eeprom_Password_Flag);
	_delay_ms(10);
	Lcd_vidWriteString("Memoy_Flag ->");
	Lcd_vidWriteChar(Eeprom_Password_Flag+0x30);
	Lcd_vidSendCommand(0xC0);
	Lcd_vidWriteString(Password);
	if (Eeprom_Password_Flag != PASSWORD_FLAG_FOUND)
	{
		Uart_vidSendByte('\n');
		Uart_vidSendByte('\r');
		Uart_vidSendString("Enter New Password: ");

		Password_New(Password);

		Try_again:

		Uart_vidSendByte('\n');
		Uart_vidSendByte('\r');
		Uart_vidSendString("Confirm New Password: ");

		Password_New(Password_Confirmation);

		Compare_Function_Flag = Compare_Array(Password,Password_Confirmation);

		if (Compare_Function_Flag == 0)
		{
			Eeprom_u8WriteByte(0,0,Password[0]);
			_delay_ms(10);
			Eeprom_u8WriteByte(0,1,Password[1]);
			_delay_ms(10);
			Eeprom_u8WriteByte(0,2,Password[2]);
			_delay_ms(10);
			Eeprom_u8WriteByte(0,3,Password[3]);
			_delay_ms(10);
			Eeprom_u8WriteByte(0,4,1);

			Uart_vidSendByte('\n');
			Uart_vidSendByte('\r');
			Uart_vidSendString("Password Updated Sucessfully on Eeprom...");
		}
		else
		{
			Uart_vidSendByte('\n');
			Uart_vidSendByte('\r');
			Uart_vidSendString("Wrong Password,Try Again");
			goto Try_again;
		}


	}

	else
	{
		Password_Modify_flag=0;
		Uart_vidSendByte('\n');
		Uart_vidSendByte('\r');
		Uart_vidSendString("Do You Want To Modify The Password..? (Y/N)");
		if (Uart_u8RecieveByte()=='y')
		{
			Try_Password_again:
			Password_Modify_flag++;
			if(Password_Modify_flag == 4)
			{
				Uart_vidSendByte('\n');
				Uart_vidSendByte('\r');
				Uart_vidSendString("Modifying Password Is Blocked... ");
				goto End_ALL_This;
			}
			Uart_vidSendByte('\n');
			Uart_vidSendByte('\r');
			Uart_vidSendString("Enter Password: ");

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



			Password_New(Password_Modify);

			if (Compare_Array(Password,Password_Modify)== 0)
			{
				Eeprom_u8WriteByte(0,4,PASSWORD_FLAG_Not_FOUND);
				_delay_ms(10);
				Password_Modify_flag=0;

				goto Start_Again;
			}

			else
			{

				Uart_vidSendByte('\n');
				Uart_vidSendByte('\r');
				Uart_vidSendString("Password Wrong! ");
				goto Try_Password_again;
			}
		}
		else
		{
			goto End_ALL_This;
		}


	}
	End_ALL_This:
	Uart_vidSendByte('\n');
	Uart_vidSendByte('\r');
	Uart_vidSendString("                             End Of Session        ");
	while(1);
	return 0;
}


void Password_New(u8 arr[])
{

	i=0;
	while(i != 4)
	{
		arr[i]=Uart_u8RecieveByte();
		Uart_vidSendByte('*');
		i++;
	}
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
