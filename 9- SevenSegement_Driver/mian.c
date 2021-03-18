/*
 * mian.c
 *
 *  Created on: Feb 9, 2020
 *      Author: eslam
 */
#include"../Lib/datatype.h"
#include"../Lib/Bit_math.h"
#include"SevenSegement_int.h"
#define F_CPU 8000000
#include<util/delay.h>

int main(void)
{
	u8 x,y;
	SevenSegement_INIT(1);
	SevenSegement_INIT(2);
	x=0;
	y=0;
	for(;;)
	{



		SevenSegment_DisplayNum(1,y);
		_delay_ms(500);
		y++;
		if(y==10)
		{
			y=0;
		SevenSegment_DisplayNum(2,x);

		x++;
		if (x==10)
			x=0;

		}
	}




	return 0;
}
