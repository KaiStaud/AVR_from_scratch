/*
 * ADC_Full_Course.c
 *
 * Created: 07.10.2019 14:38:34
 * Author : kai-s
 */ 

#include <avr/io.h>
#include "setup.h"
#include "stdio.h"

#define F_CPU 16000000
#include <util/delay.h>
#include "lcd-routines.h"

volatile uint16_t ADC_result; 

int main(void)
{	char value[4];
	setup_core();	
	_delay_ms(500);
	lcd_init();
	lcd_clear();
	 /* Replace with your application code */
	
    while (1) 
    {		while()
			lcd_setcursor(0,1);
			ADC_result = ADC;
			sprintf(value, "%d", ADC_result);
			lcd_string(value);
		
	}
}

