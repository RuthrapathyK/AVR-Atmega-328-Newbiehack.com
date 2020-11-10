/*
 * Game with buttons and LED.c
 *
 * Created: 25-Aug-20 3:50:33 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB&=~(1<<DDD4);	//button pin input
  DDRD&=~(1<<DDD7);
  
  PORTB|=(1<<DDD4); //pull up input pin
  PORTD|=(1<<DDD7);
  
  DDRD|=(1<<DDD5);
  DDRD|=(1<<DDD6);
  DDRD|=(1<<DDD7);//LED pins output
  DDRB|=(1<<DDB0);
  DDRB|=(1<<DDB1);
  DDRB|=(1<<DDB3);
  unsigned int LED_set_1=0;
  unsigned int LED_set_2=0;
    while (1) 
    {
		if((PINB>>4)==0)      /*button 1 pressed */
		{
		 while(1)
		  {
			if((PINB>>4)==1)
			{
				LED_set_1++;
				switch (LED_set_1)
				{
					case 1:
					PORTD|=(1<<5);
					break;
					case 2:
					PORTD|=(1<<6);
					break;
					case 3:
					PORTD|=(1<<7);
					break;
					case 4:
					for(int i=0;i<=5;i++)
					{
						PORTD|=(1<<5);					//increment led pin
						PORTD|=(1<<6);
						PORTD|=(1<<7);
						_delay_ms(5000);
						PORTD&=~(1<<5);
						PORTD&=~(1<<6);
						PORTD&=~(1<<7);
						_delay_ms(5000);
						
					}
					LED_set_1=0;
					LED_set_2=0;
					break;
					default:
					break;
				}
				break;
			}
		}
	}
		if((PIND>>DDD7)==0)/*button 2 pressed */
		{
				while(1)
				{
					if((PIND>>DDD3)==1)
					{
						LED_set_2++;
						switch (LED_set_2)
						{
							case 1:
							PORTB|=(1<<3);
							break;
							case 2:
							PORTB|=(1<<1);
							break;
							case 3:
							PORTB|=(1<<0);
							break;
							case 4:
							for(int i=0;i<=5;i++)
							{		
								PORTB|=(1<<3);					//increment led pin
								PORTB|=(1<<1);
								PORTB|=(1<<0);
								_delay_ms(5000);
								PORTB&=~(1<<3);
								PORTB&=~(1<<1);
								PORTB&=~(1<<0);
								_delay_ms(5000);
						
							}
							LED_set_1=0;
							LED_set_2=0;
							break;
							default:
								break;
						}
							break;
						}	
		}
    }
 }
	}

