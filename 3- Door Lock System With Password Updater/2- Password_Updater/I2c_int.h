/*
 * I2c_init.h
 *
 *  Created on: Jul 2, 2020
 *      Author: eslam
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_


#define I2C_u8START_COND_STATUS					0x08
#define I2C_u8REPEATED_START_COND_STATUS		0x10
#define I2C_u8SLAVE_ADDRESS_WRITE_STATUS		0x18
#define I2C_u8SLAVE_ADDRESS_READ_STATUS			0x40
#define I2C_u8DATA_STATUS						0x28

void I2c_vidInit(void);

void I2c_vidSendStart(void);

void I2c_vidSendStop(void);

void I2c_vidSendSlaveAddress(u8 SlaveAddress);

void I2c_vidSendData(u8 Data);

u8   I2c_u8ReceiveData(void);

u8   I2c_u8CheckStatus(u8 ExpectedStatus);



#endif /* I2C_INT_H_ */
