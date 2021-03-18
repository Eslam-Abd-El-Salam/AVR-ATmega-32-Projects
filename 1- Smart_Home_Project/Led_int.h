/*
 * Led_int.h
 *
 *  Created on: Feb 6, 2020
 *      Author: eslam
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#define LED_u8NUM_1   1
#define LED_u8NUM_2   2
#define LED_u8NUM_3   3
#define LED_u8NUM_4   4
#define LED_u8NUM_5   5
#define LED_u8NUM_6   6
#define LED_u8NUM_7   7
#define LED_u8NUM_8   8

void Led_vidInit(u8 LedId);
void Led_vidTurnOn(u8 LedId);
void Led_vidTurnOff(u8 LedId);

#endif /* LED_INT_H_ */
