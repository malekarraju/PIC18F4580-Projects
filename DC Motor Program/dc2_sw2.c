#include <p18f4580.h>

#define IN1 PORTCbits.RC0
#define IN2 PORTCbits.RC1
#define E1 PORTCbits.RC2
#define IN3 PORTCbits.RC6
#define IN4 PORTCbits.RC7
#define E2 PORTCbits.RC5
#define SW1 PORTBbits.RB3
#define SW2 PORTBbits.RB6

void main(void)
{

	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;
	TRISCbits.RC2 = 0;

	TRISCbits.RC6 = 0;
	TRISCbits.RC5 = 0;
	TRISCbits.RC7 = 0;

	ADCON1 = 0x0f;

	TRISBbits.RB3 = 1;
	TRISBbits.RB6 = 1;

	while(1)
	{

		if(SW1 == 0)
		{
			IN1 = 1;
			IN2 = 0;
			  E1 = 1;
		}
		else
		{
			  E1 = 0;
		}
		if(SW2 == 0)
		{
			IN3 = 0;
			IN4 = 1;
			  E2 = 1;
		}
		else
		{
			  E2 = 0;
		}
	}
}