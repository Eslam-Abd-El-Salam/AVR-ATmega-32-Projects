/*
 * Lcd_int.h
 *
 *  Created on: Jan 31, 2020
 *      Author: eslam
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

void Lcd_vidINIT(void);
void Lcd_vidSendCommand(u8 Cmd);
void Lcd_vidWriteChar(u8 Char);

#endif /* LCD_INT_H_ */
