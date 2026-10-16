#include <p18f4580.h>

#define IN1 PORTCbits.RC0
#define IN2 PORTCbits.RC1
#define E PORTCbits.RC2

void main(void)
{

	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;
	TRISCbits.RC2 = 0;

	while(1)
	{
		IN1 = 1;
		IN2 = 0;
		  E = 1;
	}
}