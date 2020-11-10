/*
 * SPI Slave.c
 *
 * Created: 07-Nov-20 1:53:47 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include "MyUSART.h"

/*int main(void)
{
	USART_Init(9600);
	DDRB=1<<4;
	SPCR|=1<<SPE;//When the SPE bit is written to one, the SPI is enabled. This bit must be set to enable any SPI operations
	
	SPCR|=1<<DORD;//When the DORD bit is written to one, the LSB of the data word is transmitted first
	
	SPCR&=~(1<<MSTR);//This bit selects Master SPI mode when written to one
	
	SPCR&=~(1<<CPOL|1<<CPHA);//Selecting Transferring Mode
	
	SPCR&=~(1<<SPR1|1<<SPR0);//Clock select
	SPSR&=~(1<<SPI2X);
    Replace with your application code 
	unsigned char a=0x00;
    while (1) 
    {
		USART_Transmit('x');
			while(!(SPSR & (1<<SPIF)))
			{
			}
		USART_Transmit('y');
			a=SPDR;
			USART_Transmit(a);
			a=0x00;
			
    }
}*/

int main()
{

while(1)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)))
	;
	/* Return Data Register */
	x=SPDR;
	USART_Transmit(x);
	x=0x00;
	
}
}