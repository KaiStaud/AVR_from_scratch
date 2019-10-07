/*
 * setup.c
 *
 * Created: 07.10.2019 14:39:09
 *  Author: kai-s
 */
#include "avr/io.h"
#include "setup.h" 

void setup_core(void)
{
	/* Setup ADC Port */
	ADC_Port &=~ (1<<ADC_Pin);
	ADMUX |=(1<<REFS0);
	ADCSRA |= (1<<ADIF)|(1<<ADIE)|(1<<ADEN)|(1<<ADSC);
	
}