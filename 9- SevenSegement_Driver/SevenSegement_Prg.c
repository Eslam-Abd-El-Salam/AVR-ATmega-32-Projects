/*
 * Segement_Prg.c
 *
 *  Created on: Feb 9, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/Bit_math.h"
#include"Dio_int.h"
#include"SevenSegement_int.h"
#include"SevenSegement_cfg.h"


void SevenSegement_INIT(u8 LedId)
{
	switch(LedId)
	{
	case RHIGHT_SEVEN_SEGEMENT:
		Dio_vidSetPinDir(LEDA_u8ID_1,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDB_u8ID_2,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDC_u8ID_3,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDD_u8ID_4,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDE_u8ID_5,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDF_u8ID_6,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDG_u8ID_7,DIO_u8OUTPUT);
     	Dio_vidSetPinDir(LEDG_u8ID_8,DIO_u8OUTPUT);

		break;

	case LEFT_SEVEN_SEGEMENT:

		Dio_vidSetPinDir(LEDA_u8ID_2_1,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDB_u8ID_2_2,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDC_u8ID_2_3,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDD_u8ID_2_4,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDE_u8ID_2_5,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDF_u8ID_2_6,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDG_u8ID_2_7,DIO_u8OUTPUT);
		Dio_vidSetPinDir(LEDG_u8ID_2_8,DIO_u8OUTPUT);

		break;
	}
}


void SevenSegment_TurnOn(u8 LedId)
{
	switch(LedId)
	{

	case RHIGHT_SEVEN_SEGEMENT:

		Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8LOW);
		Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8LOW);
		Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8LOW);
		Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8LOW);
		Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8LOW);
		Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8LOW);
		Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);


		break;

	case LEFT_SEVEN_SEGEMENT:

		Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8LOW);
		Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8LOW);
		Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8LOW);
		Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8LOW);
		Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8LOW);
		Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8LOW);
		Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8HIGH);
		break;
	}

}

void SevenSegment_TurnOff(u8 LedId)
{

	switch(LedId)
	{

	case RHIGHT_SEVEN_SEGEMENT:

		Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);
		break;

	case LEFT_SEVEN_SEGEMENT:
		Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8HIGH);
		Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8HIGH);
		break;
	}
}






void SevenSegment_DisplayNum(u8 LedId,u8 Num)
{
	switch(LedId)
	{
	case RHIGHT_SEVEN_SEGEMENT:

		switch(Num)
		{
		case ZERO:

			Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8LOW);
			Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8LOW);
			Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8LOW);
			Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8LOW);
			Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8LOW);
			Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);
			break;

		case ONE:

			Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8LOW);
			Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8LOW);
			Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);
			break;


		case TWO:

			Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8LOW);
			Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8LOW);
			Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8LOW);
			Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8LOW);
			Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);
			break;

		case THREE:

			Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8LOW);
			Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8LOW);
			Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8LOW);
			Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8LOW);
			Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);
			break;

		case FOUR:

			Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8LOW);
			Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8LOW);
			Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);

			break;

		case FIVE:

			Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8LOW);
			Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8LOW);
			Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8LOW);
			Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);
			break;



		case SIX:

			Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8LOW);
			Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8LOW);
			Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8LOW);
			Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8LOW);
			Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);
			break;



		case SEVEN:

			Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8LOW);
			Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8LOW);
			Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8LOW);
			Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);
			break;

		case EIGHT:

			Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8LOW);
			Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8LOW);
			Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8LOW);
			Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8LOW);
			Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8LOW);
			Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);

			break;
		case NINE:

			Dio_vidSetPinVal(LEDA_u8ID_1,DIO_u8LOW);
			Dio_vidSetPinVal(LEDB_u8ID_2,DIO_u8LOW);
			Dio_vidSetPinVal(LEDC_u8ID_3,DIO_u8LOW);
			Dio_vidSetPinVal(LEDD_u8ID_4,DIO_u8LOW);
			Dio_vidSetPinVal(LEDE_u8ID_5,DIO_u8HIGH);
			Dio_vidSetPinVal(LEDF_u8ID_6,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_7,DIO_u8LOW);
			Dio_vidSetPinVal(LEDG_u8ID_8,DIO_u8HIGH);

			break;

		}
		break;



		case LEFT_SEVEN_SEGEMENT:


			switch(Num)
			{
			case ZERO:

				Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8LOW);
				Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8LOW);
				Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8LOW);
				Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8LOW);
				Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8LOW);
				Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8LOW);
				break;

			case ONE:

				Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8LOW);
				Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8LOW);
				Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8LOW);
				break;


			case TWO:

				Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8LOW);
				Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8LOW);
				Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8LOW);
				Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8LOW);
				Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8LOW);
				break;

			case THREE:

				Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8LOW);
				Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8LOW);
				Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8LOW);
				Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8LOW);
				Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8LOW);
				break;

			case FOUR:

				Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8LOW);
				Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8LOW);
				Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8LOW);

				break;

			case FIVE:

				Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8LOW);
				Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8LOW);
				Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8LOW);
				Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8LOW);
				break;



			case SIX:

				Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8LOW);
				Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8LOW);
				Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8LOW);
				Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8LOW);
				Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8LOW);
				break;



			case SEVEN:

				Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8LOW);
				Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8LOW);
				Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8LOW);
				Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8LOW);
				break;

			case EIGHT:

				Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8LOW);
				Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8LOW);
				Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8LOW);
				Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8LOW);
				Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8LOW);
				Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8LOW);

				break;
			case NINE:

				Dio_vidSetPinVal(LEDA_u8ID_2_1,DIO_u8LOW);
				Dio_vidSetPinVal(LEDB_u8ID_2_2,DIO_u8LOW);
				Dio_vidSetPinVal(LEDC_u8ID_2_3,DIO_u8LOW);
				Dio_vidSetPinVal(LEDD_u8ID_2_4,DIO_u8LOW);
				Dio_vidSetPinVal(LEDE_u8ID_2_5,DIO_u8HIGH);
				Dio_vidSetPinVal(LEDF_u8ID_2_6,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_7,DIO_u8LOW);
				Dio_vidSetPinVal(LEDG_u8ID_2_8,DIO_u8LOW);

				break;

			}


			break;
	}

}






























































































































