// 0 -> LED AN ; 1
#define F_CPU 16000000UL
#include <kamavr.h>
//Verbinden mit COM 9
#include "avr/io.h"
#include "util/delay.h"

/*
int main()

{	uint8_t val=0xFF;
	DDRC = 0xFF;
	while(1)
	{
		val--;
		PORTC = val;
		_delay_ms(500);
	}
}
*/
/*int main()
{
DDRC = 0xFF;
uint8_t val = 0;

while(1)
{
val++;
PORTC = ~val;
_delay_ms(500);

}

}
*/

int main()
{int i;
DDRC = 0xFF;
DDRA = 0x00;

for(i=0; i<8; i++)
{

PORTC ^= 0xFF;
_delay_ms(500);}

while(1)
{

PORTC = ~PINA; 
}
}



