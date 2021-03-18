/*
 * Dio_prg.c
 *
 *  Created on: Mar 9, 2020
 *      Author: eslam
 */

#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"

#include"Dio_priv.h"
#include"Dio_int.h"




void Dio_vidSetPinDir(u8 Pin,u8 Dir)
{

	u8 PinLoc;
	u8 PortId;

	PortId=Pin/8;
	PinLoc=Pin%8;
	switch (PortId)
	{
	case 0:
		if (Dir== DIO_u8OUTPUT)
		{
			SET_BIT (DDRA.Byte,PinLoc);
		}

		else
		{
			CLR_BIT(DDRA.Byte,PinLoc);
		}
		break;

	case 1:
		if (Dir==DIO_u8OUTPUT)
		{
			SET_BIT(DDRB.Byte,PinLoc);
		}

		else
		{
			CLR_BIT(DDRB.Byte,PinLoc);
		}
		break;

	case 2:
		if (Dir==DIO_u8OUTPUT)
		{
			SET_BIT(DDRC.Byte,PinLoc);
		}

		else
		{
			CLR_BIT(DDRC.Byte,PinLoc);
		}
		break;

	case 3:
		if (Dir==DIO_u8OUTPUT)
		{
			SET_BIT(DDRD.Byte,PinLoc);
		}

		else
		{
			CLR_BIT(DDRD.Byte,PinLoc);
		}
		break;



	}


}







void Dio_vidSetPinVal(u8 Pin,u8 Val)
{


	u8 PinLoc;
	u8 PortId;

	PortId=Pin/8;
	PinLoc=Pin%8;
	switch (PortId)
	{
	case 0:
		if (Val==DIO_u8OUTPUT)
		{
			SET_BIT(PORTA.Byte,PinLoc);
		}

		else
		{
			CLR_BIT(PORTA.Byte,PinLoc);
		}
		break;

	case 1:
		if (Val==DIO_u8OUTPUT)
		{
			SET_BIT(PORTB.Byte,PinLoc);
		}

		else
		{
			CLR_BIT(PORTB.Byte,PinLoc);
		}
		break;

	case 2:
		if (Val==DIO_u8OUTPUT)
		{
			SET_BIT(PORTC.Byte,PinLoc);
		}

		else
		{
			CLR_BIT(PORTC.Byte,PinLoc);
		}
		break;

	case 3:
		if (Val==DIO_u8OUTPUT)
		{
			SET_BIT(PORTD.Byte,PinLoc);
		}

		else
		{
			CLR_BIT(PORTD.Byte,PinLoc);
		}
		break;



	}


}

u8 Dio_vidGetRegVal(u8 Pin)
{
	u8 PinLoc;
	u8 PortId;

	PortId=Pin/8;
	PinLoc=Pin%8;

	switch (PortId)
	{
	case 0:


		return GET_BIT(PINA.Byte,PinLoc);
		break;

	case 1:

		return GET_BIT(PINB.Byte,PinLoc);


		break;

	case 2:


		return GET_BIT(PINC.Byte,PinLoc);


		break;

	case 3:

		return GET_BIT(PIND.Byte,PinLoc);

		break;



	}
	return 0;
}

