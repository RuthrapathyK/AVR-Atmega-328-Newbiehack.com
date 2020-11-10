/*
 * Game on Buttons 2.c
 *
 * Created: 26-Aug-20 12:41:25 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <util/delay.h>
void button_1(void);
void button_2(void);
int LED_set_1=0;
int LED_set_2=0;
int main(void)
{
   DDRB=0b11101111;//PORT B making as LED as output
   
   PORTB|=(1<<PORTB4);//PORTB making button 1 as input and making pull up
   
   DDRD=0b01111111;//PORT D making LED as output
   
   PORTD|=(1<<PORTD7);//PORT D making button 2 as input and making pull up

	while (1) 
    {
		if((PINB>>4)==0)
		{
			while(1)
			{
				if((PINB>>4)==1)
				{
				button_1();
				break;	
				}
				//button 1 function
			}
			
		}
	 if((PIND>>7)==0)
		{
			while(1)
			{
				if((PIND>>7)==1)
				{
				button_2();
				break;//button 2 fuctions	
				}
				
			}
			
		}
			
    }
}

void button_1()
{
	LED_set_1++;
	switch (LED_set_1)
	{
	case 1:
		PORTB|=(1<<0);
		break;
	case 2:
		PORTB|=(1<<1);
		break;
	case  3:
		PORTB|=(1<<2);
		break;
	case 4:
	for(int i=0;i<4;i++)
	{
		PORTB|=(1<<0);
		PORTB|=(1<<1);
		PORTB|=(1<<2);
		_delay_ms(5000);
		PORTB&=~(1<<0);
		PORTB&=~(1<<1);
		PORTB&=~(1<<2);
		_delay_ms(5000);
		LED_set_1=0;
		LED_set_2=0;
	}
	     PORTD&=~(1<<3);
	     PORTD&=~(1<<4);
	     PORTD&=~(1<<5);
		 break;
	}
}
void button_2()
{
	LED_set_2++;
	switch (LED_set_2)
	{
		case 1:
		PORTD|=(1<<3);
		break;
		case 2:
		PORTD|=(1<<4);
		break;
		case  3:
		PORTD|=(1<<5);
		break;
		case 4:
		for(int i=0;i<4;i++)
		{
			PORTD|=(1<<3);
			PORTD|=(1<<4);
			PORTD|=(1<<5);
			_delay_ms(5000);
			PORTD&=~(1<<3);
			PORTD&=~(1<<4);
			PORTD&=~(1<<5);
			_delay_ms(5000);
			LED_set_1=0;
			LED_set_2=0;
		}
		    PORTB&=~(1<<0);
		    PORTB&=~(1<<1);
		    PORTB&=~(1<<2);
			break;
	}
}