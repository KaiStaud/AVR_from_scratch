#include <Arduino.h>

// Wait for ADC to finish Conversion
int ADC_ReadBlocking(uint8_t channel)
{
  ADMUX = channel | (1<<REFS0);
  while((ADCSRA) & (1<<ADSC));
  ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
  return(ADC);
}

// Setup ADC in Free Running Mode
// Return Value in ISR(ADC_vect)
void ADC_ReadIRQ(uint8_t channel)
{
  ADMUX = channel | (1<<REFS0);
  ADCSRA = 0x07 | (1<<ADIE)|(1<<ADEN)|(1<<ADSC);
  sei();
}

// Set ADC Speed
void ADC_SetSpeed(uint8_t speed)
{
  ADCSRA = speed |(1<<ADEN)|(1<<ADSC);
}


void setup() {
  // put your setup code here, to run once:
  // Print over USART
  Serial.begin(9600);
  Serial.print("ADC Example");


  /*  Setup ADC in Single Conversion - Polling Mode */
  ADMUX = 1<< REFS0; // Use VCC as Reference
  ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
  while((ADCSRA) & (1<<ADSC));
  ADC_ReadIRQ(0);
}

void loop() {
  // put your main code here, to run repeatedly:
 
}

ISR(ADC_vect)
{
  Serial.println(ADC);
  ADCSRA |=(1<<ADSC);
}
