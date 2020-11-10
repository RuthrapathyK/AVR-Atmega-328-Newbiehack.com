/*
 * LCD_4bit.c
 *
 * Created: 01-Sep-20 10:38:50 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "MyLCD_4bit.h"

int main(void)
{
    LCD_initialise();
	int k=0;
	Send_string("Hi Ruthra");
    while (1) 
    {
		LCD_clear();
		Send_string("WELCOME");
	    Set_cursor(1,0);
	    Send_variable(k);/* Replace with your application code */
		_delay_ms(20000);
		k++;
		
	}
}

