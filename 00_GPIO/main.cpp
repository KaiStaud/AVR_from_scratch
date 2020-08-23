#include <Arduino.h>

/* Acces Builtin LED: D13 -> B5 */
#define LED_BUILTIN_PORT PORTB
#define LED_BUILTIN_PIN 5

void setup()
{

}

void loop()
{

/* Set up GPIO Register to Output only at Bit 5*/
DDRB = 1<< LED_BUILTIN_PIN;

  /* Never exit loop */
  while(true)
  {
    /* Toggle Complete Register */
    LED_BUILTIN_PORT ^= 0xFF;
    delay(1000);
  }

}