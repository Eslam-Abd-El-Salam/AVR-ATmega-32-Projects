/*
 * I2c_prg.c
 *
 *  Created on: Jul 2, 2020
 *      Author: eslam
 */
#include "../Lib/datatype.h"
#include "../Lib/Bit_math.h"

#include "I2c_int.h"
#include "I2c_cfg.h"
#include "I2c_priv.h"

void I2c_vidInit(void)
{
	/* Enable I2C */
	SET_BIT(TWCR,2);

	/* Enable Acknowledge */
	SET_BIT(TWCR,6);

	/* Set the SCL frequency to 250 KHz */
	CLR_BIT(TWSR,1);
	CLR_BIT(TWSR,0);
	TWBR = 2;

	/* Set the device own address with 1 and disable general call */
	TWAR = 2;

}

void I2c_vidSendStart(void)
{
	/* Send start
	 * Clear the flag to start the next job
	 * keep the I2C enabled */
	TWCR = (1<<7) | (1<<5) | (1<<2);

	/* wait till the job is done and the flag is raised */
	while(GET_BIT(TWCR,7) == 0);
}

void I2c_vidSendStop(void)
{
	/* Send stop
	 * Clear the flag to start the next job
	 * keep the I2C enabled */
	TWCR = (1<<7) | (1<<4) | (1<<2);
}

void I2c_vidSendSlaveAddress(u8 SlaveAddress)
{
	/* load the slave address in the register
	 * to be transmitted on the buss */
	TWDR = SlaveAddress;

	/* Clear the flag to start the next job
	 * keep the I2C enabled */
	TWCR = (1<<7) | (1<<2);

	/* wait till the job is done and the flag is raised */
	while(GET_BIT(TWCR,7) == 0);
}

void I2c_vidSendData(u8 Data)
{
	/* load the data in the register
	 * to be transmitted on the buss */
	TWDR = Data ;

	/* Clear the flag to start the next job
	 * keep the I2C enabled */
	TWCR = (1<<7) | (1<<2);

	/* wait till the job is done and the flag is raised */
	while(GET_BIT(TWCR,7) == 0);
}

u8   I2c_u8ReceiveData(void)
{
	/* Clear the flag to start the next job
	 * keep the I2C enabled */
	TWCR = (1<<7) | (1<<2);

	/* wait till the job is done and the flag is raised */
	while(GET_BIT(TWCR,7) == 0);

	/* return the received byte */
	return TWDR;
}

u8   I2c_u8CheckStatus(u8 ExpectedStatus)
{
	/* variable to return the checking result */
	u8 ReturnValue;

	/* Check the expected value with the current status of the last job */
	if( (TWSR & 0xF8) == ExpectedStatus )
	{
		/* return check is Ok */
		ReturnValue = 1;
	}
	else
	{
		/* return check is Not Ok */
		ReturnValue = 0;
	}
	/* return the status */
	return ReturnValue;
}


