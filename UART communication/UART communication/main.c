#include "MyUSART.h"
#include <util/delay.h>
int main()
{
	USART_Init(9600);
	while (1)
	{
		USART_Transmit_String("Hi");
		_delay_ms(50000);
	}
}