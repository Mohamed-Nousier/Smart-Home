/*
 * SPI.h
 *
 * Created: 2/8/2021 6:14:11 PM
 *  Author: 20115
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#define F_CPU 16000000UL  // any fixed number must have casting(in our case it is unsigned long)
#include <util/delay.h>

/*we will replacing the bits numbers with their name*/
#define SS 4 // enabling bit set to 0 to enable
#define MOSI 5 // master out slave in
#define MISO 6 // master in slave out
#define SCK 7  // clock


/*SS bit controlling */
#define Slave_EN() (PORTB &=~(1<<SS))
#define Slave_DS() (PORTB |=(1<<SS))


/*function prototyping*/
typedef enum
{
	Master = 0, 
	Slave
}SPI_StatusTypes;
	
	
void SPI_Init(SPI_StatusTypes status);
void SPI_TxRx(unsigned char data);  // it will be one function since it is based on circular shift

#endif /* SPI_H_ */