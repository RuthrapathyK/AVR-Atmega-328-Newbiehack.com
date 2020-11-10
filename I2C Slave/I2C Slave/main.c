/*
 * I2C Slave.c
 *
 * Created: 21-Sep-20 2:32:12 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "MyUSART.h"
int main(void)
{
	USART_Init(9600);
	DDRD|=1<<2;
   TWAR|=1<<0;//Enable Response for the general call
   TWCR|=(1<<TWEA|1<<TWEN);
   TWCR&=~(1<<TWSTA|1<<TWSTO);
  volatile char a;
    while (1) 
    {
		
		/*for (int i=7;i>=0;i--)
		{
			if(((TWSR&(1<<i))>>i)==1)
			USART_Transmit('1');
			if (((TWSR&(1<<i))>>i)==0)
			USART_Transmit('0');
			
		}
		//USART_Transmit('B');
		USART_Transmit('\n');
		//_delay_ms(5000);*/
		 while ((TWCR &(1<<TWINT))==1);
		 {
				 if((TWSR & 0xF8) ==0x70)
				 {
					  TWCR&=~(1<<TWINT);
					 TWCR&=~(1<<TWSTO);
					 TWCR|=1<<TWINT|1<<TWEA;
				 }
		
				 if((TWSR & 0xF8) ==0x90)
				 {
					 TWCR&=~(1<<TWINT);
					 a=TWDR;
					 TWCR&=~(1<<TWSTO);
					 TWCR|=1<<TWINT|1<<TWEA;
					 PORTD^=1<<2;
					 USART_Transmit(a);
					 a=0x00; 
					 
				 }
				 if((TWSR & 0xF8) ==0xA0)
				 {
					  TWCR&=~(1<<TWINT);
					
					 TWCR|=(1<<TWEA);
					 TWCR&=~(1<<TWSTA|1<<TWSTO);
					 TWCR|=1<<TWINT;
					
				 }
				
		 }
    
	
	}
}

