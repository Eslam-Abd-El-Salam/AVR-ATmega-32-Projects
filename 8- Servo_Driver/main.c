/*
 * main.c
 *
 *  Created on: Mar 1, 2020
 *      Author: eslam
 */
#include"../Lib/dataType.h"
#include"Servo_int.h"
#include"Servo_cfg.h"
#define F_CPU 8000000
#include<util/delay.h>

int main(void)

{

	Servo_vidInit(2);
	while(1)
	{
	Servo_vidMoveServo(2,90);
	_delay_ms(1000);
	Servo_vidMoveServo(2,0);
	_delay_ms(1000);
	}




}
