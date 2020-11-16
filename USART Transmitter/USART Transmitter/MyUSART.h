#ifndef MyUSART
#define  MyUSART
#include <avr/io.h>

void USART_Init(int);
void USART_Transmit(unsigned char data);
void USART_Transmit_String(char *p);
unsigned char USART_Receive(void);


void USART_Init(int x)
{
	#define F_CPU 8000000 		//Change the value according to the clock frequency mine is 8MHz
	#define BAUDRATE x
	#define CALC ((F_CPU/16/BAUDRATE)-1)						//Global interrupt clear
	PRR&=~(1<<PRUSART0);		//Disable power reduction for USART
	UBRR0H=(CALC>>8);			//Set Baud rate
	UBRR0L = CALC;
	UCSR0B |= (1<<RXEN0|1<<TXEN0);//Enable Receive and transmit bit
}
void USART_Transmit(unsigned char data)
{
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1<<UDRE0)))
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}
unsigned char USART_Receive(void)
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)))
	;
	/* Get and return received data from buffer */
	return UDR0;
}
void USART_Transmit_String( char *p)
{
	int i=0;
	while(*(p+i)!='\0')
	{
		 USART_Transmit(*(p+i));
		 i++;
	}
}
#endif
