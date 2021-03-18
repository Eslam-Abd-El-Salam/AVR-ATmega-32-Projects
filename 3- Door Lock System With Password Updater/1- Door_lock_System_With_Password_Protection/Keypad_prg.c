/*
 * Keypad_prg.c
 *
 *  Created on: Feb 13, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Dio_int.h"
#include"Keypad_int.h"
#include"Keypad_cfg.h"



void Keypad_vidInit(void)
{
	Dio_vidSetPinDir(KEYPAD_u8RAW1_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8RAW2_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8RAW3_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8RAW4_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8COULMN1_PIN,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8COULMN2_PIN,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8COULMN3_PIN,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8COULMN4_PIN,DIO_u8INPUT);

	Dio_vidSetPinVal(KEYPAD_u8RAW1_PIN,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8RAW2_PIN,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8RAW3_PIN,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8RAW4_PIN,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8COULMN1_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8COULMN2_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8COULMN3_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8COULMN4_PIN,DIO_u8HIGH);

}



u8 Keypad_GetKey(void)
{
	u16 temp;
	u8 temp_1,temp_2,temp_3,temp_4;

	Dio_vidSetPinVal(KEYPAD_u8RAW1_PIN,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8RAW2_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8RAW3_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8RAW4_PIN,DIO_u8HIGH);

	temp_1=Dio_vidGetRegVal(KEYPAD_u8COULMN1_PIN);
	temp_2=Dio_vidGetRegVal(KEYPAD_u8COULMN2_PIN);
	temp_3=Dio_vidGetRegVal(KEYPAD_u8COULMN3_PIN);
	temp_4=Dio_vidGetRegVal(KEYPAD_u8COULMN4_PIN);

	temp=temp_1+temp_2*10+temp_3*100+temp_4*1000;


	switch(temp)
	{
	case CLOUMN1_ENABLE_VALUE:
		return 1;
	case CLOUMN2_ENABLE_VALUE:
		return 2;
	case CLOUMN3_ENABLE_VALUE:
		return 3;
	case CLOUMN4_ENABLE_VALUE:
		return '+';
	}

	Dio_vidSetPinVal(KEYPAD_u8RAW1_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8RAW2_PIN,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8RAW3_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8RAW4_PIN,DIO_u8HIGH);

	temp_1=Dio_vidGetRegVal(KEYPAD_u8COULMN1_PIN);
	temp_2=Dio_vidGetRegVal(KEYPAD_u8COULMN2_PIN);
	temp_3=Dio_vidGetRegVal(KEYPAD_u8COULMN3_PIN);
	temp_4=Dio_vidGetRegVal(KEYPAD_u8COULMN4_PIN);
	temp=temp_1+temp_2*10+temp_3*100+temp_4*1000;

	switch(temp)
	{
	case CLOUMN1_ENABLE_VALUE:
		return 4;
	case CLOUMN2_ENABLE_VALUE:
		return 5;
	case CLOUMN3_ENABLE_VALUE:
		return 6;
	case CLOUMN4_ENABLE_VALUE:
		return '-';
	}

	Dio_vidSetPinVal(KEYPAD_u8RAW1_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8RAW2_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8RAW3_PIN,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8RAW4_PIN,DIO_u8HIGH);

	temp_1=Dio_vidGetRegVal(KEYPAD_u8COULMN1_PIN);
	temp_2=Dio_vidGetRegVal(KEYPAD_u8COULMN2_PIN);
	temp_3=Dio_vidGetRegVal(KEYPAD_u8COULMN3_PIN);
	temp_4=Dio_vidGetRegVal(KEYPAD_u8COULMN4_PIN);
	temp=temp_1+temp_2*10+temp_3*100+temp_4*1000;

	switch(temp)
	{
	case CLOUMN1_ENABLE_VALUE:
		return 7;
	case CLOUMN2_ENABLE_VALUE:
		return 8;
	case CLOUMN3_ENABLE_VALUE:
		return 9;
	case CLOUMN4_ENABLE_VALUE:
		return '*';
	}


	Dio_vidSetPinVal(KEYPAD_u8RAW1_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8RAW2_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8RAW3_PIN,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8RAW4_PIN,DIO_u8LOW);

	temp_1=Dio_vidGetRegVal(KEYPAD_u8COULMN1_PIN);
	temp_2=Dio_vidGetRegVal(KEYPAD_u8COULMN2_PIN);
	temp_3=Dio_vidGetRegVal(KEYPAD_u8COULMN3_PIN);
	temp_4=Dio_vidGetRegVal(KEYPAD_u8COULMN4_PIN);
	temp=temp_1+temp_2*10+temp_3*100+temp_4*1000;

	switch(temp)
	{
	case CLOUMN1_ENABLE_VALUE:
		return '#';
	case CLOUMN2_ENABLE_VALUE:
		return 0;
	case CLOUMN3_ENABLE_VALUE:
		return '=';
	case CLOUMN4_ENABLE_VALUE:
		return '/';
	}

	return KEYPAD_u8NO_KEY;
}
