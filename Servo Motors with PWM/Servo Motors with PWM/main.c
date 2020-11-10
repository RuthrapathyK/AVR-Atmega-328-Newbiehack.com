/*
 * Servo Motors with PWM.c
 *
 * Created: 04-Sep-20 2:30:35 AM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{
//Enable timer interrupt OCIE1A
   
      DDRB|=(1<<1);//make OC1A as ouput by setting (DDR_OC1A = 1) 
   TCCR1A|=(1<<7);
   TCCR1A|=(1<<6);//configure compare output mode
   
   TCCR1B|=(1<<WGM13|1<<WGM12|1<<CS11);		//waveform generation mode select(select Fast PWM mode with ICR1 as a top value) 
	TCCR1A|=(1<<WGM11);
	TCCR1A&=~(1<<WGM10);
   

  //presacclar 8
   ICR1=13333;//ICR1 write top value
   
  	//OCR1A for seting compare match value
	
    while (1) 
    {
	 OCR1A=ICR1-666;
	 _delay_ms(50000);
	 OCR1A=ICR1-(666*2);
	 _delay_ms(50000);

    }
}

/*OCF1A interrupt vector
{
	Toggle OC1A state by setting compare output mode bits to toggle mode (COM1A1:0 = 1)
*/