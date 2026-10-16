#include <p18f4580.h>

#define Dir_LED_D TRISDbits.RD5 
#define Dir_LED_C TRISCbits.RC0 


#define LED_D PORTDbits.RD5 
#define LED_C PORTCbits.RC0 

#define ON 1 
#define OFF 0

void Delay(int);

void main(void)
{
	Dir_LED_D = 0;
	Dir_LED_C = 0;
	
	while(1)
	{
		LED_D = ON;
			Delay(100);
		LED_D = OFF;
			Delay(100);		
		
		LED_C = ON;
			Delay(100);
		LED_C = OFF;
			Delay(100);
	}
	
	return;
}

void Delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
		
	return;
}