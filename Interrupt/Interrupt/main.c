/*
 * Interrupt.c
 *
 * Created: 24-Aug-20 8:56:30 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    
	DDRB|=(1<<0);//LED as output
	
	PORTB&=~(1<<0);//making LED low initially
	
	PRR&=~(PRTIM1);//timer initialize
	
	sei();//enabing global interrupt
	
	TIMSK1|=(1<<OCIE1A);//enable timmer interrupt
	
	OCR1A=10000;//write data to output compare match register
	
	TCCR1B&=~(1<<WGM13);//wgm to ctc mode
	TCCR1B|=(1<<WGM12);
	TCCR1B&=~(1<<WGM11);
	TCCR1B&=~(1<<WGM10);
	
	
	TCCR1B|=(1<<CS12);//clock select and prescalar
	TCCR1B&=~(1<<CS11);
	TCCR1B|=(1<<CS10);
	while (1) 
    {
    }
}
	ISR(TIMER1_COMPA_vect)
	{
	TIFR1&=~(1<<OCF1A);	//serve interrupt
	PORTB^=(1<<0);
	}
		
