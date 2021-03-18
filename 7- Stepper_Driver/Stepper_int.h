/*
 * Stepper_int.h
 *
 *  Created on: Feb 10, 2020
 *      Author: eslam
 */

#ifndef STEPPER_INT_H_
#define STEPPER_INT_H_

#define HALFRIGHT_ROTATION_ANGLE   45
#define RIGHT_ROTATION_ANGLE       90
#define STRAIGHT_ROTATION_ANGLE    180
#define REFLEX_ROTATION_ANGLE      270
#define FULL_ROTATION_ANGLE        360

void Stepper_INIT();
void Stepper_TurnRight(u32 Angle);
void Stepper_TurnLeft(u32 Angle);

#endif /* STEPPER_INT_H_ */
