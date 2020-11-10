/*
 * EEPROM.c
 *
 * Created: 07-Nov-20 8:05:03 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include "MyUSART.h"
#include <util/delay.h>
unsigned char EEPROM_Read(unsigned char address)
{
		while((EECR&(1<<EEPE))>>EEPE==1)
		;
	    EEARL=address;
	    EECR|=1<<EERE;
	    __asm("nop");
	    return EEDR;
}
void EEPROM_Write(unsigned char address,unsigned char data)
{
		while((EECR&(1<<EEPE))>>EEPE==1)
		;
		while((SPMCSR&(1<<SPMEN))>>SPMEN==1)
		;
		EEARL=address;
		EEDR=data;
		EECR&=~(1<<EEPM1|1<<EEPM0);
		EECR|=1<<EEMPE;
		EECR|=1<<EEPE;
		_delay_ms(10);
}
int main(void)
{
	USART_Init(9600);
	USART_Transmit(EEPROM_Read(0x00));
    while (1) 
    {
    }
}

