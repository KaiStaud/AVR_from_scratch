// 0 -> LED AN ; 1
#define F_CPU 16000000UL
#include <kamavr.h>
//Verbinden mit COM 9
#include "avr/io.h"
#include "util/delay.h"


int main()
{
int poti;
init_lcd();
// ADC PORT als Input setzen
PORTA = 0xFF;
// ADC0 konfigurieren
/* 5V Reference Voltage */
ADMUX = (1<<REFS0);
/* Set maximum PSC */
ADCSRA = (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
/* Enable and Start conversion */
ADCSRA = (1<<ADEN)|(1<<ADSC);
 
/* Loop will never be left*/
while(1)
{
	/* wait for Conversion to complete */
	while(ADCSRA & (1<<ADSC));

	/* Read + Display */
	poti = ADC;
	num_lcd(0x80,poti/4);
	/* Start next conversion */
	ADCSRA |= (1<<ADSC);
}

}
