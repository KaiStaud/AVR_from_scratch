#include "Arduino.h"
#include "ADC.h"

void init_ADC()
{
ADMUX = (1<<REFS0);
ADCSRA = (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
}

int read_ADC(int channel)
{
ADMUX |= channel | (1<<REFS0); // keep AVCC as reference  
ADCSRA |= (1<<ADEN)|(1<<ADSC); // enable and start ADC

while(ADCSRA &0x40); // check if ADSC is still set,
                    // will be reset whenn finished
return ADC;
}