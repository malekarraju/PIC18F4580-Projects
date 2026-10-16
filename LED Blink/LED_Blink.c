#include<p18f4580.h>

void Delay(int);

void main()
{
  //Initialize all variable onece
TRISC = 0x00;

	while(1) // Infinite loop
	{
		PORTC = 0xff; // leds on
		Delay(100);   // stop
		PORTC = 0x00; // leds off
		Delay(100);   // stop
	}
}

void Delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
}
	