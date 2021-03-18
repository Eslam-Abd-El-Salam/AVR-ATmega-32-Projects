/*
 * Uart_prv.h
 *
 *  Created on: Jun 19, 2020
 *      Author: eslam
 */

#ifndef UART_PRV_H_
#define UART_PRV_H_


#define UDR   (*(volatile u8*) 0x2C)
#define UCSRA (*(volatile u8*) 0x2B)
#define UCSRB (*(volatile u8*) 0x2A)
#define UCSRC (*(volatile u8*) 0x40)
#define UBRRH (*(volatile u8*) 0x40)
#define UBRRL (*(volatile u8*) 0x29)


#endif /* UART_PRV_H_ */
