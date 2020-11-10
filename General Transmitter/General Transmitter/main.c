/*
 * General Transmitter.c
 *
 * Created: 23-Sep-20 3:21:36 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <util/delay.h>
uint8_t volatile i=0;
void clock_start()
{
	PORTD|=1<<PORTD7;
}
void clock_stop()
{
	PORTD&=~(1<<PORTD7);
}
void Send_data(unsigned char a)
{
	i=0;
	for(i=0;i<=7;i++)
	{
		if(((a>>i)&(0x01))==1)
		{
		PORTD|=1<<PORTD6;
		}
		else if(((a>>i)&(0x01))==0)
		{
		PORTD&=~(1<<PORTD6);	
		}
	
		clock_start();
		clock_stop();
	}
	_delay_ms(500);
}
void Send_string(char *p)
{
	int volatile c=0;
	while((*(p+c))!='\0')
	{
		Send_data(*(p+c));
		c++;
	}
}
int main(void)
{
	DDRD|=1<<PORTD7;
	DDRD|=1<<PORTD6;
	Send_string("No matter how stunning your book cover is, or how amazing the story, choosing the right font for your book can make a big difference when you publish your book.");
    while (1) 
    {
		
	}
}

