/*
 * SPI Master.c
 *
 * Created: 07-Nov-20 1:15:39 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "MyUSART.h"
/*int main(void)
{
	DDRB|=(1<<5|1<<3);//Enable the pins with the data direction
	PORTB|=1<<2;
	
	SPCR|=1<<SPE;//When the SPE bit is written to one, the SPI is enabled. This bit must be set to enable any SPI operations
	
	SPCR|=1<<DORD;//When the DORD bit is written to one, the LSB of the data word is transmitted first
	
	SPCR|=1<<MSTR;//This bit selects Master SPI mode when written to one
 
	SPCR&=~(1<<CPOL|1<<CPHA);//Selecting Transferring Mode
	
	SPCR|=1<<SPR0;//Clock select
	SPSR&=~(1<<SPI2X);
	
	PORTB&=~(1<<2);
    while (1) 
    {

		SPDR='A';
			while(((SPSR)&(1<<7))==0)
	{				
	}
		_delay_ms(1000);
    }
}*/
void SPI_Transmit(unsigned char a)
{
		SPDR = a;
		/* Wait for transmission complete */
		while(!(SPSR & (1<<SPIF)))
		;
}
void SPI_Transmit_String(char *p)
{
	unsigned int i=0;
	while(*(p+i)!='\0')
	{
		SPI_Transmit(*(p+i));
		_delay_ms(50);
		i++;
	}
}
void SPI_Init()
{
	/* Set MOSI and SCK output, all others input */
	DDRB = (1<<3)|(1<<5|1<<2);
	//PORTB|=1<<2;/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR);//|(1<<SPR1|1<<SPR0)
	//SPSR|=1<<SPI2X;
}
int main()
{
		
SPI_Init();
//SPI_Transmit('a');
SPI_Transmit_String("HiruthrapathyEnable SPI, Master, set clock rate fck/16 */Letter series is a logical arrangement of letters of English alphabet arranged in a specified pattern. In this, a series of letters, groups of letters or combination of letters and numbers is given. Each group or single element is called term. The terms of the series form a certain pattern. So first required to identify this pattern and find the missing term in the given series which will satisfy the pattern.");
while(1)
{
}
}
