#include<p18f4580.h>

#define Dir_SW1 TRISCbits.RC0
#define Switch1 PORTCbits.RC0

#define Dir_SW2 TRISCbits.RC3
#define Switch2 PORTCbits.RC3

#define Dir_Led1 TRISDbits.RD0
#define Led1 PORTDbits.RD0

#define Dir_Led2 TRISDbits.RD3
#define Led2 PORTDbits.RD3

#define ON 1
#define OFF 0

void main()
{
	Dir_SW1 = 1;
	Dir_SW2 = 1;

	Dir_Led1 = 0;
	Dir_Led2 = 0;
	
	while(1)
	{
		if(Switch1 == 0)
			Led1 = ON;
		else 
			Led1 = OFF;

		if(Switch2 == 0)
			Led2 = ON;
		else 
			Led2 = OFF;
    }
}
		
	