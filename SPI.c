/*
 * SPI.c
 *
 * Created: 2/8/2021 6:14:03 PM
 *  Author: 20115
 */ 

#include "SPI.h"

void SPI_Init(SPI_StatusTypes status)
{
	switch(status)
	{
		case Master:
		DDRB |= ((1<<SCK)|(1<<MOSI)|(1<<SS));
		DDRB &=~ (1<<MISO);
		SPCR |= ((1<<SPE)|(1<<MSTR));
		break;
		case Slave:
		DDRB |= (1<<MISO);
		DDRB &=~ ((1<<SCK)|(1<<MOSI)|(1<<SS));
		SPCR |= (1<<SPE);
		break;
	}
}


unsigned char SPI_TxRx(void)
{
	//SPDR = data;
	while(!((SPSR>>SPIF)&1)); // check if the transmitting is complete
	return SPDR;
}