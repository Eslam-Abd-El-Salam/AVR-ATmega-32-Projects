/*
 * Stepper_Prg.c
 *
 *  Created on: Feb 10, 2020
 *      Author: eslam
 */
#define F_CPU 8000000
#include<util/delay.h>
#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Dio_int.h"
#include"Stepper_int.h"
#include"Stepper_cfg.h"

void Stepper_INIT()
{
	Dio_vidSetPinDir(STEP_u8PIN_1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(STEP_u8PIN_2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(STEP_u8PIN_3,DIO_u8OUTPUT);
	Dio_vidSetPinDir(STEP_u8PIN_4,DIO_u8OUTPUT);
}


void Stepper_TurnRight(u32 Angle)
{

	u32 i;

	switch(Angle)
	{
	case HALFRIGHT_ROTATION_ANGLE:

		for(i=0;i<64;i++)
		{
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8HIGH);
			_delay_ms(2);
		}
		break;

	case RIGHT_ROTATION_ANGLE:

		for(i=0;i<128;i++)
		{
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8HIGH);
			_delay_ms(2);
		}
		break;

	case REFLEX_ROTATION_ANGLE:

		for(i=0;i<192;i++)
		{
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8HIGH);
			_delay_ms(2);
		}

		break;

	case STRAIGHT_ROTATION_ANGLE:

		for(i=0;i<256;i++)
		{
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8HIGH);
			_delay_ms(2);
		}

		break;

	case FULL_ROTATION_ANGLE:

		for(i=0;i<512;i++)
		{
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8HIGH);
			_delay_ms(2);
		}

		break;
	}
}

void Stepper_TurnLeft(u32 Angle)
{

	u16 i;

	switch(Angle)
	{
	case HALFRIGHT_ROTATION_ANGLE:

		for(i=0;i<64;i++)
		{
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8HIGH);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
		}
		break;

	case RIGHT_ROTATION_ANGLE:

		for(i=0;i<128;i++)
		{
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8HIGH);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
		}
		break;

	case REFLEX_ROTATION_ANGLE:

		for(i=0;i<192;i++)
		{
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8HIGH);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
		}

		break;

	case STRAIGHT_ROTATION_ANGLE:

		for(i=0;i<256;i++)
		{
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8HIGH);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
		}

		break;

	case FULL_ROTATION_ANGLE:

		for(i=0;i<512;i++)
		{
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8HIGH);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);

			Dio_vidSetPinVal(STEP_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(STEP_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_3,DIO_u8LOW);
			Dio_vidSetPinVal(STEP_u8PIN_4,DIO_u8LOW);
			_delay_ms(2);
		}

		break;
	}
}
