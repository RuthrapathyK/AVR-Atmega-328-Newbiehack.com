#include <avr/io.h>
#include <avr/interrupt.h>
#include "MyUSART.h"
int main(void)
{
	DDRB|=1<<5;
	sei();
	UCSR0B|=1<<RXCIE0;
	UCSR0A|=1<<RXC0;
	USART_Init(9600);
	while(1)
	{
	}	
}
ISR(USART_RX_vect)
{
	char b=USART_Receive();
	if(b=='a')
	PORTB^=1<<5;
}