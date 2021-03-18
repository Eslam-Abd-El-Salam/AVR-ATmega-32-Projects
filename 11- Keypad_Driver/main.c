/*
 * main.c
 *
 *  Created on: Feb 14, 2020
 *      Author: eslam
 */

#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Dio_int.h"
#include"Keypad_int.h"
#include"Keypad_cfg.h"


int main(void)
{
u8 i;

	Keypad_INIT();
	while(1)
	{
	i=Keypad_GetKey();

	if (i==1)
	{
		Dio_vidSetPinDir(DIO_u8PIN_16,DIO_u8OUTPUT);
		Dio_vidSetPinVal(DIO_u8PIN_16,DIO_u8HIGH);
	}




	}
	return 0;
}
