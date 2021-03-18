/*
 * SevenSegement_int.h
 *
 *  Created on: Feb 9, 2020
 *      Author: eslam
 */

#ifndef SEVENSEGEMENT_INT_H_
#define SEVENSEGEMENT_INT_H_

#define RHIGHT_SEVEN_SEGEMENT       1
#define LEFT_SEVEN_SEGEMENT         2
#define ZERO    0
#define ONE     1
#define TWO     2
#define THREE   3
#define FOUR    4
#define FIVE    5
#define SIX     6
#define SEVEN   7
#define EIGHT   8
#define NINE    9
void SevenSegment_INIT(u8 LedId);
void SevenSegment_TurnOn(u8 LedId);
void SevenSegment_TurnOff(u8 LedId);
void SevenSegment_DisplayNum(u8 LedId,u8 Num);


#endif /* SEVENSEGEMENT_INT_H_ */
