/*
 * I2C Master.c
 *
 * Created: 19-Sep-20 7:34:11 PM
 * Author : DELL
 */ 
#ifndef MyI2C
#define MyI2C

#include <avr/io.h>
#include <acv.h>
#define START 0x08

#define  MT_SLA_ACK 0x18
#define MT_DATA_ACK 0x28

void i2c_Send_string(char *p);
void i2c_Send_character(char b);
void i2c_Init(unsigned char slave_address_hexadecimal);
void i2c_Stop(void);

int main(void)
{

i2c_Init(0x00);

i2c_Send_string("These 18 English short stories are easy, engaging and will make you think hard ...");
i2c_Send_character('\n');
i2c_Send_string("These will not only improve your English reading comprehension but also open ..."); 
i2c_Send_character('\n');
i2c_Send_string(" (normal) tone as he discusses the details of the copier and office refrigerator...");
i2c_Stop();
	while(1)
	{
		
	}
	
}
void ERROR(uint8_t a)
{
	/*if(a==1)
	USART_Transmit_String("Start condition not initialized");
	if(a==2)
	USART_Transmit_String("Slave Acknowledgement not received");
	if(a==3)
	USART_Transmit_String("Data Acknowledgement not received");*/
}
void i2c_Send_character(char b)
{
	TWDR = b;
	TWCR = (1<<TWINT) | (1<<TWEN);//Load DATA into TWDR register.clear TWINT bit in TWCR tostart transmission of data

	while (!(TWCR & (1<<TWINT)))//Wait for TWINT flag set. Thisindicates that the DATA hasbeen transmitted, andACK/NACK has been received.
	{
		
	}

	if ((TWSR & 0xF8)!= MT_DATA_ACK)//Check value of TWI statusregister. Mask prescaler bits. Ifstatus different fromMT_DATA_ACK go to ERROR
	ERROR(3);
}
void i2c_Send_string(char *p)
{
	uint8_t volatile i=0;
	while(*(p+i)!='\0')
	{
		i2c_Send_character(*(p+i));
		i++;
	}
}
void i2c_Init(unsigned char slave_address_hexadecimal)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);//Send START condition

	while (!(TWCR & (1<<TWINT)))	//Wait for TWINT flag set. This indicates that the STARTcondition has been transmitted
	{
	}
	if ((TWSR & 0xF8) != START)/*Check value of TWI statusregister. Mask prescaler bits. Ifstatus different from START goto ERROR*/
	ERROR(1);
	
	TWDR = slave_address_hexadecimal;
	TWCR = (1<<TWINT) |(1<<TWEN);//Load SLA_W into TWDRregister. Clear TWINT bit inTWCR to start transmission ofaddress

	while (!(TWCR & (1<<TWINT)))//Wait for TWINT flag set. Thisindicates that the SLA+W hasbeen transmitted, andACK/NACK has been received
	{
		
	}

	if ((TWSR & 0xF8) != MT_SLA_ACK)//Check value of TWI statusregister. Mask prescaler bits. Ifstatus different fromMT_SLA_ACK go to ERROR
	ERROR(2);
}
void i2c_Stop()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);	//Transmit STOP condition
}
#endif