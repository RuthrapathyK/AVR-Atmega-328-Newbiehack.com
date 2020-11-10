/*
 * Timers.c
 *
 * Created: 26-Aug-20 6:43:10 PM
 * Author : DELL
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB|=(1<<0)|(1<<1)|(1<<2);;  //making port B as output and maiking all leds low
	PORTB&=~(1<<0);
	PORTB&=~(1<<1);
	PORTB&=~(1<<2);
	
	PRR&=~(1<<PRTIM1);//initialize timmer
	
    TCCR1B|=(1<<CS12);
	TCCR1B&=~(1<<CS11);  //selecting clock sourse and defining prescaling
	TCCR1B|=(1<<CS10);
	
	int LED_number[3]={0,1,2};
		int i=0;
    while (1) 
    {
		if(TCNT1>10000)
		{
			
			TCNT1=0;
			PORTB^=(1<<LED_number[i]);
			i++;
			if(i>2) i=0;     //togling led
			
		}
	}
}

