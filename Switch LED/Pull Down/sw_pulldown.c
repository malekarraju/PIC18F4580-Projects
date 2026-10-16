#include<p18f4580.h>

#define Dir_SW TRISCbits.RC0
#define Switch PORTCbits.RC0

#define Dir_Led TRISCbits.RC6
#define Led PORTCbits.RC6


#define ON 1
#define OFF 0

void main()
{
	Dir_SW = 1;
	Dir_Led = 0;
	
	while(1)
	{
		if(Switch == 1)
			Led = ON;
		else 
			Led = OFF;
    }
}

/*
#include<p18f4580.h>

void main()
{
	TRISCbits.RC0 = 1;
	TRISCbits.RC6 = 0;

	while(1)
	{
		if(PORTCbits.RC0 == 1)
				PORTCbits.RC6 = 1;
		else 
				PORTCbits.RC6 = 0;
	}
}
*/	