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
		Slave_DS();  // ss = 1 then ~ = 0 : slave not working  (PORTB |=(1<<SS))
		SPCR |= ((1<<SPE)|(1<<MSTR));
		//SPI ->SPI_SPCR = ((1<<SPE)|(1<<MSTR));
		//SPI->SPI_SPCR.SMSTR = 1;
		//SPI->SPI_SPCR.SSPE = 1;
		break;
		case Slave:
		DDRB |= (1<<MISO);
		DDRB &=~ ((1<<SCK)|(1<<MOSI)|(1<<SS));
		SPCR |= (1<<SPE);
		break;
	}
}


 void SPI_TxRx(unsigned char data)
{
	SPDR = data;
	while(!((SPSR>>SPIF)&1)); // check if the transmitting is complete
	//return SPDR;
}