/*
 * General Receiver.c
 *
 * Created: 23-Sep-20 3:35:46 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include"MyUSART.h"
#include <util/delay.h>
#include <avr/interrupt.h>
uint8_t volatile i=0;
unsigned char x=0x00;
int main(void)
{
	USART_Init(9600);
  // DDRD&=~(1<<PORTD7);
  // PORTD&=~(1<<PORTD7);
   DDRD&=~(1<<PORTD6);
   sei();		//Enable Global Interrupt
   EICRA|=1<<ISC01|1<<ISC00;//Enable rising Edge for INT0
   EIMSK|=1<<INT0;
  
  // PORTB|=1<<5;
    while (1) 
    {
		 while(i<8)
		 {
			 
		 }
		 i=0;
		USART_Transmit(x);
		x=0x00;
		/*for(int k=0;k<=7;k++)
		{
			if(((x>>k)&(0x01))==1)
			USART_Transmit('1');
			else if(((x>>k)&(0x01))==0)
			USART_Transmit('0');
		}
		_delay_ms(5000);
		*/
    }
}
ISR(INT0_vect)
{
x|=(((PIND>>6)&(0x01))<<i);
i++;	
}
