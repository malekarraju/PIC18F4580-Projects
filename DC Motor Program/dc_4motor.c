#include <p18f4580.h>

#define EN1 PORTCbits.RC2
#define EN2 PORTCbits.RC3
#define EN3 PORTDbits.RD2
#define EN4 PORTDbits.RD3

#define SW1 PORTBbits.RB4
#define SW2 PORTBbits.RB5
#define SW3 PORTBbits.RB6
#define SW4 PORTBbits.RB7

#define CW_PATTERN 0x1D  // 0001 1101
#define ACW_PATTERN 0x2E // 0010 1110


void Dir_Pins(void); 
void All_CW(void);
void All_ACW(void);
void First2_CW(void);
void First2_ACW(void);
void Disable(void);

void main(void)
{
	Dir_Pins(); // set all pins direction

	while(1)
	{
		// SWITCH 1 
		if(SW1 == 0)  
		{
			All_CW(); // all clock wise
		}
		
		// SWITCH 2
        else if(SW2 == 0)  
		{
			All_ACW(); // all anti-clockwise
		}

		// SWITCH 3
		 else if(SW3 == 0)  
		{
			First2_CW(); // first 2 clock wise
		}

		// SWITCH 4
		 else if(SW4 == 0)  
		{
			First2_ACW(); // first 2 anti-clockwise
		}
		else
		{
			Disable();
		}
	}
}

// motor Control Function 

void Disable(void)
{
	EN1 = 0;
	EN2 = 0;
	EN3 = 0;
	EN4 = 0;
}

void First2_ACW(void)
{
	PORTC = ACW_PATTERN;
	PORTD = CW_PATTERN;
}

void First2_CW(void)
{
	PORTC = CW_PATTERN;
	PORTD = ACW_PATTERN;
}

void All_ACW(void)
{
	PORTC = ACW_PATTERN;
	PORTD = ACW_PATTERN;
}	

void All_CW(void)
{
	PORTC = CW_PATTERN;
	PORTD = CW_PATTERN;
}

void Dir_Pins(void)
{
		ADCON1 = 0x0F; // configure all analog pins as digital I/O

	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;
	TRISCbits.RC2 = 0;
	TRISCbits.RC3 = 0;
	TRISCbits.RC4 = 0;
	TRISCbits.RC5 = 0;

	TRISDbits.RD0 = 0;
	TRISDbits.RD1 = 0;
	TRISDbits.RD2 = 0;
	TRISDbits.RD3 = 0;
	TRISDbits.RD4 = 0;
	TRISDbits.RD5 = 0;

	TRISBbits.RB4 = 1;
	TRISBbits.RB5 = 1;
	TRISBbits.RB6 = 1;
	TRISBbits.RB7 = 1;

	PORTC = 0x00; // initial value for motor control outputs.
    PORTD = 0x00;
}