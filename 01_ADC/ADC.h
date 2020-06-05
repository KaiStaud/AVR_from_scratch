
#define TRUE 1
#define FALSE 0

//own macros for ADC Samplerates 
#define SPEED_125ksps 128
#define SPEED_250ksps  64
#define SPEEP_500ksps  32
#define SPEED_1Msps    16
#define SPEED_2Msps     8
#define SPEED_4Msps     4
#define SPEED_8Msps     2
#define SPEED_16Msps    1

#define SCAN_ROUTINE TRUE 
#define SINGLE_CHANNEL FALSE


void ADC_init_polled();

/* Polling Mode */
int read_ADC(int channel);

/* ISR Based Mode*/
void ADC_init_isr(void);

void ADC_set_speed(int speed);
