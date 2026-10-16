#include <p18f4580.h>

#define IN1 PORTCbits.RC0
#define IN2 PORTCbits.RC1
#define E PORTCbits.RC2
#define SWITCH PORTDbits.RD6

void main(void)
{

	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;
	TRISCbits.RC2 = 0;
	TRISDbits.RD6 = 1;

	while(1)
	{

		if(SWITCH == 0)
		{
			IN1 = 1;
			IN2 = 0;
			  E = 1;
		}
		else
		{
			  E = 0;
		}
	}
}