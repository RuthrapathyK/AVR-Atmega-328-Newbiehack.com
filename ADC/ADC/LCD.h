#ifndef MyLCD1
#define MyLCD1
#include <avr/io.h>
#include <util/delay.h>
#define DATAPIN PORTD
#define CONTROLPIN PORTB
#define DDR_DATA DDRD
#define DDR_CONTROL DDRB
#define RS 0
#define RW 1
#define EN 2

void LCD_initialise(void);
void LCD_clear(void);
void Set_cursor(int a,int b);
void Send_variable(int k);
void Send_string(char *p);
void enabling(void);
void Check_busy(void);
void Send_command(unsigned char command);
void Send_character(unsigned char character);


void Send_command(unsigned char command)
{
	Check_busy();
	DATAPIN=command;
	CONTROLPIN&=~(1<<RS);
	CONTROLPIN&=~(1<<RW);
	_delay_us(100);
	enabling();
}
void Send_character(unsigned char character)
{
	Check_busy();
	DATAPIN=character;
	CONTROLPIN|=(1<<RS);
	CONTROLPIN&=~(1<<RW);
	_delay_us(100);
	enabling();
}
void Check_busy(void)
{
	DDR_DATA=0;
	CONTROLPIN&=~(1<<RS);
	CONTROLPIN|=(1<<RW);
	_delay_us(100);
	
	while((CONTROLPIN>>7)==1)
	{
		enabling();
	}
	DDR_DATA=0xFF;
}
void enabling(void)
{
	CONTROLPIN|=(1<<EN);
	_delay_us(100);
	CONTROLPIN&=~(1<<EN);
	_delay_us(1000);
}
void Send_string(char *p)
{
	int i=0;
	while(*(p+i)!='\0')
	{
		Send_character(*(p+i));
		_delay_us(50);
		i++;
	}
}
void Send_variable(int k)
{
	char array[10];
	char t;
	int i=0,j;
	while(k!=0)
	{
		array[i]=((k%10)+48);
		k=k/10;
		i++;
	}
	array[i]='\0';
	j=i-1;
	for (i=0;i<j;i++,j--)
	{
		t=array[i];
		array[i]=array[j];
		array[j]=t;
	}
	Send_string(array);
}
void Set_cursor(int a,int b)
{
	int c;
	Send_command(0b00000010);
	_delay_ms(50);
	if(a==0)
	{
		for(c=1;c<=b;c++)
		{
			Send_command(0b00010100);
			_delay_us(100); //Right shift cursor to 1 place
		}
	}
	if(a==1)
	{
		for(c=1;c<=40;c++)
		{
			Send_command(0b00010100);
			_delay_us(100);
		}
		for(c=1;c<=b;c++)
		{
			Send_command(0b00010100);
			_delay_us(100); //Right shift cursor to 1 place
		}
		
	}
	
}
void LCD_initialise()
{
	DDR_CONTROL|=(1<<RS|1<<RW|1<<EN);
	_delay_ms(100);
	Send_command(0x01);//clear screen
	_delay_ms(50);
	Send_command(0x38);//function set
	_delay_us(100);
	Send_command(0b00001100);//display ON/OFF copntrol
	_delay_us(100);
}
void LCD_clear()
{
	Send_command(0b00000001);
	_delay_ms(50);
}
#endif