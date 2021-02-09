/*
 * Master_Final.c
 *
 * Created: 2/9/2021 5:17:15 PM
 *  Author: 20115
 */ 

#include "UART.h"
#include "SPI.h"
#include <avr/io.h>
#include <avr/interrupt.h>


volatile unsigned char  DataReceived = 0;
volatile unsigned char RxData = 0;


int main(void)
{
	sei(); // global interrupt enable
	Uart_Init();
	SPI_Init(Master);
	Slave_EN();
	HC05_vInit();  //bluetooth 
	
    while(1) 
    {
                   
		if (DataReceived == 1 ) /* when the UART finishin its job the flag will be set and the SPI will start*/
		{
   			DataReceived = 0 ;
			SPI_TxRx(RxData);
		}			  			  
    } 
} 

ISR(USART_RXC_vect)
{
	DataReceived = 1 ;
	RxData = UDR; 
}