/*
 * Servo_int.h
 *
 *  Created on: Mar 1, 2020
 *      Author: eslam
 */

#ifndef SERVO_INT_H_
#define SERVO_INT_H_

#define CHANNEL_A 1
#define CHANNEL_B 2


void Servo_vidInit(u8 Channel);
void Servo_vidMoveServo(u8 Channel,u16 Angle);

#endif /* SERVO_INT_H_ */
