#include<p18f4580.h>

#define Dir_LED TRISDbits.RD0  
#define LED PORTDbits.RD0
#define ON 1
#define OFF 0

void Delay(int);

void main(void)
{
  //Initialize all variable onece
 Dir_LED = 0;

	while(1) // Infinite loop
	{
		LED = ON; // leds on
		Delay(100);   
		LED = OFF; // leds off
		Delay(100);   
	}
}

void Delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
}
	