/*
 * Eeprom_prg.c
 *
 *  Created on: Jul 4, 2020
 *      Author: eslam
 */

#include "../Lib/datatype.h"
#include "../Lib/Bit_math.h"

#include "I2c_int.h"
#include "Eeprom_int.h"
#include "Eeprom_cfg.h"
#include "Eeprom_priv.h"

void Eeprom_vidInit(void)
{
	/* Initialize I2c */
	I2c_vidInit();
}

u8   Eeprom_u8WriteByte(u8 DeviceId, u16 Location, u8 Byte)
{
	/*********************************************************
	 * 1-Send start
	 * 2-check status
	 * 3-Send slave address with write
	 * 4-check status
	 * 5-Send location "Location for Eeprom but Data for I2c"
	 * 6-check status
	 * 7-Send Byte
	 * 8-check status
	 * 9-Send Stop
	 **********************************************************/

	/* variable to extract the slave address from the location */
	u8 SLA;

	/* Check if the requested EEPROM is Id 0 "A2 connected to GND" */
	if(DeviceId == EEPROM_u8DEVICE_0)
	{
		/* extract bit 9 and bit 8 from the location
		 * and add them in bit 2 and bit 1 in Device Slave address
		 * and remember the following:
		 * Location is 10-bits    P1 P0 xxxx xxxx
		 * Slave address is 1010 A2 P1 P0 R/W    */
		SLA = EEPROM_u8DEVICE_ADDRESS_0 | ( (Location>>8) << 1 );
	}
	/* Check if the requested EEPROM is Id 1 "A2 connected to Vcc" */
	else if(DeviceId == EEPROM_u8DEVICE_1)
	{
		/* extract bit 9 and bit 8 from the location
		 * and add them in bit 2 and bit 1 in Device Slave address
		 * and remember the following:
		 * Location is 10-bits    P1 P0 xxxx xxxx
		 * Slave address is 1010 A2 P1 P0 R/W    */
		SLA = EEPROM_u8DEVICE_ADDRESS_1 | ( (Location>>8) << 1 );
	}

	/* Sending start condition to start the frame */
	I2c_vidSendStart();

	/* Check if the start condition is transmitted by checking the hardware
	 * status with the expected status "Start condition has been transmitted" */
	if( I2c_u8CheckStatus(I2C_u8START_COND_STATUS) == 1 )
	{
		/* Sending slave address with write access */
		I2c_vidSendSlaveAddress(SLA);

		/* Check if the slave address with write access is transmitted by checking
		 * the hardware status with the expected status "Start condition has been
		 *  transmitted" ********************************************/
		if( I2c_u8CheckStatus(I2C_u8SLAVE_ADDRESS_WRITE_STATUS) == 1 )
		{
			/* Send the remaining 8-bits from the location by casting the location variable by u8
			 * Remember: it's a data from I2c perspective and location for Eeprom perspective */
			I2c_vidSendData( (u8)Location );

			/* Check if the data has been transmitted */
			if( I2c_u8CheckStatus(I2C_u8DATA_STATUS) == 1 )
			{
				/* Send the needed byte to the EEPROM to be written */
				I2c_vidSendData(Byte);

				/* Check if the data has been transmitted */
				if( I2c_u8CheckStatus(I2C_u8DATA_STATUS) == 1 )
				{
					/* Send stop condition */
					I2c_vidSendStop();

					/* return True "The function ended successfully */
					return 1;
				}
			}
		}
	}
	/* return False "The function not ended successfully */
	return 0;
}

u8   Eeprom_u8ReadByte(u8 DeviceId, u16 Location, u8* pByte)
{
	/*********************************************************
	 * 1-Send start
	 * 2-check status
	 * 3-Send slave address with write  "Dummy Write"
	 * 4-check status
	 * 5-Send location "Location for Eeprom but Data for I2c"
	 * 6-check status
	 * 7-Send Start "Repeated Start"
	 * 8-check status
	 * 9-Send Slave Address with Read access
	 * 10-check status
	 * 11-Read the received Byte
	 * 12-Send Stop
	 **********************************************************/


	/* variable to extract the slave address from the location */
	u8 SLA;

	/* Check if the requested EEPROM is Id 0 "A2 connected to GND" */
	if(DeviceId == EEPROM_u8DEVICE_0)
	{
		/* extract bit 9 and bit 8 from the location
		 * and add them in bit 2 and bit 1 in Device Slave address
		 * and remember the following:
		 * Location is 10-bits    P1 P0 xxxx xxxx
		 * Slave address is 1010 A2 P1 P0 R/W    */
		SLA = EEPROM_u8DEVICE_ADDRESS_0 | ( (Location>>8) << 1 );
	}
	/* Check if the requested EEPROM is Id 1 "A2 connected to Vcc" */
	else if(DeviceId == EEPROM_u8DEVICE_1)
	{
		/* extract bit 9 and bit 8 from the location
		 * and add them in bit 2 and bit 1 in Device Slave address
		 * and remember the following:
		 * Location is 10-bits    P1 P0 xxxx xxxx
		 * Slave address is 1010 A2 P1 P0 R/W    */
		SLA = EEPROM_u8DEVICE_ADDRESS_1 | ( (Location>>8) << 1 );
	}

	/* Sending start condition to start the frame */
	I2c_vidSendStart();

	/* Check if the start condition is transmitted by checking the hardware
	 * status with the expected status "Start condition has been transmitted" */
	if( I2c_u8CheckStatus(I2C_u8START_COND_STATUS) == 1 )
	{
		/* Sending slave address with write access */
		I2c_vidSendSlaveAddress(SLA);

		/* Check if the slave address with write access is transmitted by checking
		 * the hardware status with the expected status "Start condition has been
		 *  transmitted" ********************************************/
		if( I2c_u8CheckStatus(I2C_u8SLAVE_ADDRESS_WRITE_STATUS) == 1 )
		{
			/* Send the remaining 8-bits from the location by casting the location variable by u8
			 * Remember: it's a data from I2c perspective and location for Eeprom perspective */
			I2c_vidSendData( (u8)Location );

			/* Check if the data has been transmitted */
			if( I2c_u8CheckStatus(I2C_u8DATA_STATUS) == 1 )
			{
				/* Send repeated start to change the operation of slave from write to read */
				I2c_vidSendStart();

				/* check if the repeated start has been transmitted */
				if( I2c_u8CheckStatus(I2C_u8REPEATED_START_COND_STATUS) == 1 )
				{
					/* send slave address with read access by OR the SLA variable with 1 */
					I2c_vidSendSlaveAddress( (SLA | 0x01) );

					/* Check if the SLA with read access has been transmitted */
					if( I2c_u8CheckStatus(I2C_u8SLAVE_ADDRESS_READ_STATUS) == 1 )
					{
						/* read the received data */
						*pByte = I2c_u8ReceiveData();

						/* Send stop */
						I2c_vidSendStop();
						/* return True "The function ended successfully */
						return 1;
					}
				}
			}
		}
	}
	/* return False "The function not ended successfully */
	return 0;
}
