#include "regs.h"
#include "common.h"

#define START_ADC	ADCCON |= 1

void delay(int n);

int main(int argc, char *argv[])
{	
	ADCCON = (1 << 16) | (1 << 14) | (65 << 6);

	while(1){
		ADCTSC = (1 << 6) | (1 << 5) | 1;
		START_ADC;
		while(!(ADCCON & (1 << 15)));
		printf("x = %d\n", ADCDAT0 & 0xfff);

		ADCTSC = (1 << 7) | (1 << 4) | 2;
		START_ADC;
		while(!(ADCCON & (1 << 15)));
		printf("y = %d\n", ADCDAT1 & 0xfff);
		delay(10);
	}

	return 0;
}

void delay(int n)
{
	int i, j;
	
	for(i = 0; i < n; i ++){
		for(j = 0; j < 10000; j++){
			;
		}
	}
}
