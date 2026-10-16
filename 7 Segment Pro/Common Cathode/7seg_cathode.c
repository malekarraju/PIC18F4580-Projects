
#include<p18f4580.h>

void Delay(int);


#include<p18f4580.h>

void Delay(int);

void main()
{
	char arr[]={0x03f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
	int i;

	TRISC = 0x00;

	while(1)
	{
		for(i=0; i<=9; i++)
		{	
			PORTC = arr[i];
			Delay(100);
		}
	}
}

void Delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
}
