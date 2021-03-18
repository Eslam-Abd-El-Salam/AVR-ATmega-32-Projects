/*
 * Led_Intensity_prg.c
 *
 *  Created on: Mar 3, 2020
 *      Author: eslam
 */

#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Dio_int.h"
#include<avr/io.h>

void LedIntensity_vidInit()


{
	Dio_vidSetPinDir(DIO_u8PIN_11,DIO_u8OUTPUT);
		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
		CLR_BIT(TCCR0,2);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,0);

}
void LedIntensity_vidSetVal(u16 Val)
{
	if((Val>0) &&(Val<=255))
	{

	OCR0=Val;
	}

	else if(Val==0)
	{
		CLR_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
		Dio_vidSetPinVal(DIO_u8PIN_11,DIO_u8LOW);
	}

}
