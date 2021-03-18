/*
 * DcMotorer_prg.c
 *
 *  Created on: Mar 1, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Dio_int.h"
#include "DCM_cfg.h"
#include "DCM_int.h"


void DcMotor_vidInit(void)

{
	Dio_vidSetPinDir(DCM_u8PIN,DIO_u8OUTPUT);
}
void DcMotor_vidTurnOn(void)
{
	Dio_vidSetPinVal(DCM_u8PIN,DIO_u8HIGH);
}
void DcMotor_vidTurnOff(void)
{
	Dio_vidSetPinVal(DCM_u8PIN,DIO_u8LOW);
}
