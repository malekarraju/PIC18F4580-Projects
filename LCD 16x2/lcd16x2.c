#include<p18f4580.h>

#define RS PORTCbits.RC0
#define RW PORTCbits.RC1
#define E PORTCbits.RC2

void Delay(int);
void Lcd_Cmd(char);
void Lcd_Data(char);
void Lcd_String(const rom char*);
void Lcd_Inti();

void main()
{  
	// one time execution
	TRISD=0x00;      //Port direction
	TRISCbits.RC0=0;
	TRISCbits.RC1=0;
	TRISCbits.RC2=0;
	
	// LCD intialization
    Lcd_Inti();

    // use because program stuck here
	while(1)
	{
		Lcd_String("Welcome:");
		Lcd_Cmd(0x01);  //clear screen
	}
}

// Function Defination

void Lcd_Inti()
{	
	/* LCD initi. */
	Lcd_Cmd(0x0e); // Lcd on, Cursor on 0x0f for Blink
	Lcd_Cmd(0x01); // Clear Screen
	Lcd_Cmd(0x06); // Inc Cursor
	Lcd_Cmd(0x38); // 8 bit mode, 2 lines, 5x7 Matrix
	Lcd_Cmd(0x80); // 1st Row, 1st Pos/Col
	
}

void Lcd_String(const rom char* str)
{
	while(*str != '\0')
	{
		Lcd_Data(*str);
		str++;
	}
}

void Delay(int a)
{
	int i,j;
	for(i=0; i<100; i++)
		for(j=0; j<100; j++);
}

void Lcd_Cmd(char ch)
{
	PORTD = ch; 
	RS = 0;  // Command Mode
	// RW = 0;  // Write to LCD, connecting to ground
	E = 1;
	Delay(100);
	E = 0;
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


