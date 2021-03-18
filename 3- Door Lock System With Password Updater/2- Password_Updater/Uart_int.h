/*
 * Uart_init.h
 *
 *  Created on: Jun 19, 2020
 *      Author: eslam
 */

#ifndef UART_INT_H_
#define UART_INT_H_

void Uart_vidInit(void);
void Uart_vidSendByte(u8 Byte);
u8 Uart_u8RecieveByte(void);
void Uart_vidSendString(u8* String);
#endif /* UART_INT_H_ */
