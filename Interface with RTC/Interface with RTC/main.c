/*
 * Interface with RTC.c
 *
 * Created: 19-Oct-20 10:37:29 PM
 * Author : DELL
 */ 

#include <avr/io.h>
#include "MyI2C.h"
#include <util/delay.h>
void Write_RTC(void);
void Read_RTC(void);
void i2c_Receive_RTC(void);
unsigned char a=0x00;
int main(void)
{
	USART_Init(9600);
   Write_RTC();
   
	
	
    while (1) 
    {
		Read_RTC();
		_delay_ms(5000);
    }
}
void Write_RTC(void)
{
	 i2c_Init(0b11010000);//Start condition with write enable
	 i2c_Send_data(0x00);//Address to be written
	 i2c_Send_data(0x00);//Seconds
	 i2c_Send_data(0b00111111);//Minutes
	 i2c_Send_data(0b00001111);//hours
	 i2c_Send_data(0b00000111);//day
	 i2c_Send_data(0b00110011);//date
	 i2c_Send_data(0b00011111);//month
	 i2c_Send_data(0b11111111);//year
	 i2c_Stop();
}
void Read_RTC(void)
{
	i2c_Init(0b11010000);//Start condition with write enable
	i2c_Send_data(0x00);
	i2c_Init_Read(0b11010001);
	i2c_Receive_RTC();
	i2c_Stop();
}
void i2c_Receive_RTC(void)
{
	for(int i=0;i<=5;i++)
	{
	
		TWCR = (1<<TWINT)| (1<<TWEA)|(1<<TWEN);//Load DATA into TWDR register.clear TWINT bit in TWCR tostart transmission of data
//USART_Transmit_String("Inside the loop");
		while (!(TWCR & (1<<TWINT)))//Wait for TWINT flag set. Thisindicates that the DATA hasbeen transmitted, andACK/NACK has been received.
		{
			
		}
		//USART_Transmit_String("Outside the loop");
	  
		if ((TWSR & 0xF8)!= 0x50)//Check value of TWI statusregister. Mask prescaler bits. Ifstatus different fromMT_DATA_ACK go to ERROR
		ERROR(4);
		
		    a=TWDR;
			for (int j=0;j<=7;j++)
			{
				if(((a&(1<<j))>>j)==1)
				{
					USART_Transmit('1');
				}
			
				else if(((a&(1<<j))>>j)==0)
				{
					USART_Transmit('0');
				}
			
			}
			a=0x00;
			USART_Transmit('\n');
	}
	TWCR &=~(1<<TWEA);
	TWCR |= (1<<TWINT|1<<TWEN);
	a=TWDR;
				for (int j=0;j<=7;j++)
				{
					if(((a&(1<<j))>>j)==1)
					{
						USART_Transmit('1');
					}
					
					else if(((a&(1<<j))>>j)==0)
					{
						USART_Transmit('0');
					}
					
				}
	
	a=0x00;
	USART_Transmit('\n');
	USART_Transmit('\n');
}