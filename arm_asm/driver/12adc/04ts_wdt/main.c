#include "regs.h"
#include "common.h"

#define START_ADC	ADCCON |= 1
#define WAIT_UP		ADCTSC = (1 << 8) | (1 << 7) | (1 << 6) | (1 << 4) | 3
#define	WAIT_DOWN	ADCTSC = (1 << 7) | (1 << 6) | (1 << 4) | 3
#define AUTO_PST	ADCTSC = 1 << 2
#define INT_ADC		63
#define INT_PENDNUP 	62
#define INT_WDT 	26
#define DISABLE_WDT	WTCON &= ~(1 << 5)	
#define ENABLE_WDT	WTCON |= 1 << 5	

void do_updown(void);
void do_adc(void);
void do_wdt(void);

int main(int argc, char *argv[])
{	
	ADCCON = (1 << 16) | (1 << 14) | (65 << 6);
	ADCDLY = 0xffff;
	wdt_init(10);	

	irq_request(INT_ADC, do_adc);
	irq_request(INT_PENDNUP, do_updown);
	irq_request(INT_WDT, do_wdt);
	
	WAIT_DOWN;
	
	return 0;
}

void do_wdt(void)
{
	AUTO_PST;
	START_ADC;
	WTCLRINT = 1;
}

void do_updown(void)
{
	if(ADCUPDN & 0x2){
		ADCUPDN = 0;
		DISABLE_WDT;
		WAIT_DOWN;
	}else if(ADCUPDN & 0x1){
		ADCUPDN = 0;
		ENABLE_WDT;
	}
	ADCCLRINTPNDNUP = 1;
}

void do_adc(void)
{
	printf("x = %d\ny = %d\n", ADCDAT0 & 0xfff, ADCDAT1 & 0xfff);
	ADCCLRINT = 1;
	WAIT_UP;
}
