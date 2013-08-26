#include "regs.h"
#include "common.h"

#define START_ADC	ADCCON |= 1

int main(int argc, char *argv[])
{	
	ADCCON = (1 << 16) | (1 << 14) | (65 << 6);
	START_ADC;
	while(!(ADCCON & (1 << 15)));
	printf("adc = %d\n", ADCDAT0 & 0xfff);
	return 0;
}
