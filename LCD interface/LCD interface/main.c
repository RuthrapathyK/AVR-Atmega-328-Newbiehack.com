#include "MyLCD.h"
int main()
{
	LCD_initialise();
	int k=5,l=10;
	while(1)
	{
		LCD_clear();
		Send_string("Ruthrapathy");
		Set_cursor(1,0);
		Send_variable(k);
		_delay_ms(5000);
		LCD_clear();
		Send_string("Ruthrapathy");
		Set_cursor(1,0);
		Send_variable(l);
		_delay_ms(5000);
	}
}