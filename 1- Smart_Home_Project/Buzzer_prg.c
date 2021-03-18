/*
 * Buzzer_prg.c
 *
 *  Created on: Mar 1, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Dio_int.h"
#include"Buzzer_cfg.h"
#include"Buzzer_int.h"


void Buzz_vidInit(void)

{
	Dio_vidSetPinDir(Buzz_u8PIN,DIO_u8OUTPUT);
}
void Buzz_vidTurnOn(void)
{
	Dio_vidSetPinVal(Buzz_u8PIN,DIO_u8HIGH);
}
void Buzz_vidTurnOff(void)
{
	Dio_vidSetPinVal(Buzz_u8PIN,DIO_u8LOW);
}
