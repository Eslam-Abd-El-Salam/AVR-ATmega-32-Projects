/*
 * Servo_prg.c
 *
 *  Created on: Mar 1, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include<avr/io.h>
#include"Dio_int.h"
#include"Servo_int.h"
#include"Servo_cfg.h"

void Servo_vidInit(u8 Channel)
{
	switch(Channel)
	{
	case CHANNEL_A:
		Dio_vidSetPinDir(Servo_u8PIN_A,DIO_u8OUTPUT);
		SET_BIT(TCCR1A,7);
		// Compare OUTPUT Mode For Channel A
		CLR_BIT(TCCR1A,6);

		SET_BIT(TCCR1A,1);      //WGM10 TCCRA
		CLR_BIT(TCCR1A,0);      //WGM11 TCCRA
		// To control Wave Form Generation Modes
		SET_BIT(TCCR1B,4);      //WGM12 TCCRB
		SET_BIT(TCCR1B,3);      //WGM13 TCCRB

		CLR_BIT(TCCR1B,2);
		SET_BIT(TCCR1B,1);      //Clock select
		CLR_BIT(TCCR1B,0);

		break;

	case CHANNEL_B:
		Dio_vidSetPinDir(Servo_u8PIN_B,DIO_u8OUTPUT);
		SET_BIT(TCCR1A,5);
		// Compare OUTPUT Mode For Channel B
		CLR_BIT(TCCR1A,4);

		SET_BIT(TCCR1A,1);      //WGM10 TCCRA
		CLR_BIT(TCCR1A,0);      //WGM11 TCCRA
		// To control Wave Form Generation Modes
		SET_BIT(TCCR1B,4);      //WGM12 TCCRB
		SET_BIT(TCCR1B,3);      //WGM13 TCCRB

		CLR_BIT(TCCR1B,2);
		SET_BIT(TCCR1B,1);      //Clock select
		CLR_BIT(TCCR1B,0);

		break;

	}

}


void Servo_vidMoveServo(u8 Channel,u16 Angle)
{
	ICR1=20000;

	switch(Channel)
	{
	case CHANNEL_A:
		if ((Angle>=0) && (Angle<=180))
		{


			OCR1A=(((Angle-0)*((2500-400)/(180-0)))+400);

		}
		break;

	case CHANNEL_B:
		if ((Angle>=0) && (Angle<=180))
		{


			OCR1B=(((Angle-0)*((2500-400)/(180-0)))+400);

		}
		break;
	}


}



