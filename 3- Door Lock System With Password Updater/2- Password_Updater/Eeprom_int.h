/*
 * Eeprom_int.h
 *
 *  Created on: Jul 4, 2020
 *      Author: eslam
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

#define EEPROM_u8DEVICE_0     0
#define EEPROM_u8DEVICE_1     1

void Eeprom_vidInit(void);

u8   Eeprom_u8WriteByte(u8 DeviceId, u16 Location, u8 Byte);

u8   Eeprom_u8ReadByte(u8 DeviceId, u16 Location, u8* pByte);


#endif /* EEPROM_INT_H_ */
