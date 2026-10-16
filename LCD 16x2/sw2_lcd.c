#include<p18f4580.h>

#define SW1 PORTCbits.RC0
#define SW2 PORTCbits.RC1
#define RS PORTCbits.RC5
#define E PORTCbits.RC6

void Delay(int);
void Lcd_Cmd(char);
void Lcd_Data(char);
void Lcd_String(const rom char*);
void Lcd_Initi();

void main(void)
{
	TRISC = 0x03;
	TRISD = 0x00;	

	Lcd_Initi();
	
	while(1)
	{
		if(SW1 == 0)
		{
		Lcd_String("Welcome");
		Lcd_Cmd(0x01);
		}
		if(SW2 == 0)
		{
		Lcd_String("Raju Malekar");
		Lcd_Cmd(0x01);
		}
	}

	return;
}

void Lcd_String(const rom char* str)
{
	while(*str != '\0')
	{
		Lcd_Data(*str);
		str++;
	}
}

void Lcd_Data(char dt)
{
	PORTD = dt; 
	RS = 1;  // Data Mode
	// RW = 0;  // Write to LCD, connecting to ground
	E = 1;
	Delay(100);
	E = 0;
}

void Lcd_Initi()
{
	Lcd_Cmd(0x0e); // Lcd on, curser on
	Lcd_Cmd(0x01); // clear screen
	Lcd_Cmd(0x06); // inc cursor
	Lcd_Cmd(0x38); // 2 lines, 5x8 matrix
	Lcd_Cmd(0x80); // 1st row, 1st pos/col
}

void Lcd_Cmd(char ch)
{
	PORTD = ch;
	RS = 0;
	E = 1;
	Delay(100);
	E = 0;
}

void Delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
	return;
}
