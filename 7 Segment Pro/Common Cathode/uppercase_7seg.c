#include<p18f4580.h>
#define SWITCH PORTAbits.RA0 

void Delay(int);
void main()
{
	char arr_upc[] = {0x77,0x39,0x79,0x71,0x3D,0x76,0x06,
					  0x1E,0x38,0x3F,0x73,0x6D, 0x3E};
	char arr_lowc[] = {0x7C,0x58,0x5E,0x74,0x04,0x54,0x5C,
					   0x67,0x50,0x78,0x1c,0x6E};
	int count1=0, count2=0;

	ADCON1 = 0x0F;  
	TRISAbits.RA0 = 1;
	TRISC = 0x00;
    TRISD = 0x00;

	while(1)
	{
		if(SWITCH == 0)
		{   
			PORTC = arr_upc[count1];
			PORTD = arr_lowc[count2];
			Delay(200);

			
			if(count1 == 12) count1 = 0;
			else count1++;

			if(count2 == 11) count2 = 0;
			else count2++;				
		}
	}
}	

void Delay(int a)
{
	int i, j;
  	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
}