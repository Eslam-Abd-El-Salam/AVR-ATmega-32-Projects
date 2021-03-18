/*
 * main.c
 *
 *  Created on: Apr 22, 2020
 *      Author: eslam
 */

#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Dio_int.h"
#include"Uart_int.h"




int main(void)
{

	u8 App_u8RecievedData;

	Uart_vidInit();

	Dio_vidSetPinDir(DIO_u8PIN_1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_3,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_4,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_5,DIO_u8OUTPUT);





	while(1)
	{

		App_u8RecievedData = Uart_u8RecieveByte();

		if (App_u8RecievedData == 'F')
		{
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8HIGH);

		}


		else if (App_u8RecievedData == 'B')
		{
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_4,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_5,DIO_u8HIGH);

		}


		else if (App_u8RecievedData == 'L')
		{
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_4,DIO_u8HIGH);

		}
		else if (App_u8RecievedData == 'R')
		{
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8HIGH);


		}



		else
		{
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_4,DIO_u8LOW);

			if (App_u8RecievedData == 'u')
				Dio_vidSetPinVal(DIO_u8PIN_5,DIO_u8LOW);
			if ((App_u8RecievedData != 'u') && (App_u8RecievedData != 'R'))
					Dio_vidSetPinVal(DIO_u8PIN_5,DIO_u8LOW);
		}


	}

	return 0;

}



