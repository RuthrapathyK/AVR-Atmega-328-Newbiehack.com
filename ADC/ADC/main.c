/*
 * ADC.c
 *
 * Created: 30-Aug-20 3:18:03 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "LCD.h"

int main(void)
{
	LCD_initialise();
   PRR&=~(1<<PRADC);  //written 0 to enable adc
   
   ADCSRA|=(1<<ADPS2);//prescalar
   ADMUX|=(1<<ADLAR); //right adjusted to become 10 bit;
   ADCSRA |=(1<<ADIE);//enable adc interrupt
   ADCSRA|=(1<<ADEN); //enable adc for AVcc and A0 channel comes to effect
   ADMUX&=~(1<<REFS1);   
   ADMUX|=(1<<REFS0);	//write 01 in ADMUX to select AVcc with external capacitors
    
	ADMUX&=~(1<<MUX3|1<<MUX2|1<<MUX1|1<<MUX0);//write 0000 in ADMUX to select A0 channel
	
	
	
	
	
	sei();//enable global interrupt
	
	
		
	while (1) 
    {
   ADCSRA |=(1<<ADSC); //start conversion

    }
}
ISR(ADC_vect)
{
	int b=ADCL;
	int a=ADCH;
	int c=(a<<8)|b;
	Set_cursor(0,0);
	Send_variable(c);
	Send_character(' ');
	_delay_ms(1000);
}

