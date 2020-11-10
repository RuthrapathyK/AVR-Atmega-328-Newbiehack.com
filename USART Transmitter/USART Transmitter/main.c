/*
 * USART Transmitter.c
 *
 * Created: 19-Sep-20 7:04:39 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include "MyUSART.h"
#include <util/delay.h>
int main(void)
{
    USART_Init(9600);/* Replace with your application code */
    while (1) 
    {
		USART_Transmit_String("HELLO Ruthrapathy!!How are you?Hope you are good");
		_delay_ms(1000);
    }
}

