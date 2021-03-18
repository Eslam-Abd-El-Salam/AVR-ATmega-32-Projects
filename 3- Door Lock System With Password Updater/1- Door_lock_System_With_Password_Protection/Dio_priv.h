/*
 * Dio_priv.h
 *
 *  Created on: Mar 10, 2020
 *      Author: eslam
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_


typedef union {

	struct{

		u8 b0:1;
		u8 b1:1;
		u8 b2:1;
		u8 b3:1;
		u8 b4:1;
		u8 b5:1;
		u8 b6:1;
		u8 b7:1;
	}Bits;
  u8 Byte;

}Reg_Type;
                                                 //DDR Registers
#define DDRA   (*((volatile Reg_Type*)0x3A))
#define DDRB   (*((volatile Reg_Type*)0x37))
#define DDRC   (*((volatile Reg_Type*)0x34))
#define DDRD   (*((volatile Reg_Type*)0x31))

                                                 //PORT Registers
#define PORTA  (*((volatile Reg_Type*)0x3B))
#define PORTB  (*((volatile Reg_Type*)0x38))
#define PORTC  (*((volatile Reg_Type*)0x35))
#define PORTD  (*((volatile Reg_Type*)0x32))

                                                 //PIN Registers
#define PINA   (*((volatile Reg_Type*)0x39))
#define PINB   (*((volatile Reg_Type*)0x36))
#define PINC   (*((volatile Reg_Type*)0x33))
#define PIND   (*((volatile Reg_Type*)0x30))





#endif /* DIO_PRIV_H_ */
