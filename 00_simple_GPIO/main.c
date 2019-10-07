/*
 * 00_GPIO.c
 *
 * Created: 05.10.2019 12:59:55
 * Author : kai-s
 */ 

#include <avr/io.h>
/* Taktfrequenz des externen Quarz */
/* muss vorher deklariert werden */
#define  F_CPU 16000000

#include <util/delay.h>

/* Port und Pin der verbundenen LED */
#define LED_Port PINB
#define LED_Pin  7

int main(void)
{uint16_t delay_time = 500;	
	
	/*---------Begin MCU Setup---------------*/
	
	/* 7. Bit von PORTB 1 setzen (Ausgang)*/
	DDRB |= (1<<LED_Pin);
/* 1. Bit von PORTB  0 setzen (Eingang) */
	DDRB &= ~(1<<0);
	
	/*----------End MCU Setup---------------*/
	
	
    /* Replace with your application code */
    while (1) 
    {	if(PINB & (1<<PB0)) // Wenn erstes Bit 1 = 5V
		{
			LED_Port |= (1<<LED_Pin);
		}
		
		else
		{
		_delay_ms(delay_time);
		/* Pin setzen */
		LED_Port |= (1<<LED_Pin);
		_delay_ms(delay_time);
		/* Pin resetten */
		LED_Port &=~(1<<LED_Pin);
		}
    }
}

