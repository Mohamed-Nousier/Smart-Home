/*
 * Slave_Final.c
 *
 * Created: 2/9/2021 5:17:49 PM
 *  Author: 20115
 */ 

#include <avr/io.h>
#include "SPI.h"


volatile unsigned char Data;

int main(void)
{
	DDRD |=((1<<0)|(1<<1)|(1<<2));
	SPI_Init(Slave);
	
	
    while(1)
    {
		Data = SPI_TxRx();
		switch (Data)
		{
			case '0' :
			// Toggle ROOM1: LED0
			PORTD ^= (1<<0);
			break;
			case '1' :
			// Toggle ROOM2: LED1
			PORTD ^= (1<<1);
			break;
			case '2' :
			// Toggle ROOM3: LED2
			PORTD ^= (1<<2);
			break;
			default:
			// Wrong Entry
			break;
		}
		
		
		
	}	
}