/*
 * Keypad_int.h
 *
 *  Created on: Feb 13, 2020
 *      Author: eslam
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#define CLOUMN1_ENABLE_VALUE 1110
#define CLOUMN2_ENABLE_VALUE 1101
#define CLOUMN3_ENABLE_VALUE 1011
#define CLOUMN4_ENABLE_VALUE 111
#define KEYPAD_u8NO_KEY 0xff
void Keypad_vidInit(void);
u8 Keypad_GetKey(void);


#endif /* KEYPAD_INT_H_ */
