/*
 * I2c_priv.h
 *
 *  Created on: Jul 2, 2020
 *      Author: eslam
 */

#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_

#define TWAR      (*(volatile u8*) 0x22)
#define TWBR      (*(volatile u8*) 0x20)
#define TWCR      (*(volatile u8*) 0x56)
#define TWDR      (*(volatile u8*) 0x23)
#define TWSR      (*(volatile u8*) 0x21)


#endif /* I2C_PRIV_H_ */
