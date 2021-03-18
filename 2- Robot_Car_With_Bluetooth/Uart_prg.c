/*
 * Uart_prg.c
 *
 *  Created on: Jun 19, 2020
 *      Author: eslam
 */

#include"../Lib/datatype.h"
#include"../Lib/BIT_math.h"
#include"Uart_prv.h"

void Uart_vidInit(void)
{
	u8 Temp_u8UcsrcData;

	SET_BIT(UCSRB,4);    // Enable RX
	SET_BIT(UCSRB,3);   //Enable TX



	Temp_u8UcsrcData = 0; //Clear Variable to set new configuration  variable

	CLR_BIT(UCSRB,2);   // Character size 8bits
	SET_BIT(Temp_u8UcsrcData,2);
	SET_BIT(Temp_u8UcsrcData,1);

	CLR_BIT(Temp_u8UcsrcData,6);

	CLR_BIT(Temp_u8UcsrcData,5); // Disable Parity Mode
	CLR_BIT(Temp_u8UcsrcData,4);

	CLR_BIT(Temp_u8UcsrcData,3);  // 1 stop bit

	SET_BIT(Temp_u8UcsrcData,7);    //Select UCSRC Register

	UCSRC = Temp_u8UcsrcData;       //0b1xxxxxxx Writing USCRC configuration in the register

	UBRRH=0;  // Set baud rate "9600"
	UBRRL=51;



}



u8 Uart_vidSendByte(u8 Byte)
{

	while (GET_BIT(UCSRA,5) == 0);  //Waiting UDRE Flag comes up
	UDR = Byte;      // Update UDR register with new data to be sent


}





u8 Uart_u8RecieveByte(void)
{

	while (GET_BIT(UCSRA,7) == 0);  //Waiting RX complete Flag comes up

	return UDR;    // Read UDR " Receive Byte"


}
