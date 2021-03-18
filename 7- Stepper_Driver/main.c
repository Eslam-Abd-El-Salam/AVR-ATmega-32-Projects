/*
 * main.c
 *
 *  Created on: Feb 10, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Stepper_int.h"
#define F_CPU 8000000
#include<util/delay.h>


int main (void)
{

	Stepper_INIT();
	Stepper_TurnRight(90);

}
