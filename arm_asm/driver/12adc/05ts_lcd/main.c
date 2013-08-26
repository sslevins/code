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
void change_pic(int n);
int if_next(void);
int cal_val(int arr[], int n);

int new_x = 0;
int old_x = 0;
int flag = 1;
int val_x[10] = {0};

int main(int argc, char *argv[])
{	
	ADCCON = (1 << 16) | (1 << 14) | (65 << 6);
	ADCDLY = 0xffff;
	wdt_init(10);	
	lcd_init();

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
		change_pic(if_next());
		WAIT_DOWN;
	}else if(ADCUPDN & 0x1){
		ADCUPDN = 0;
		flag = 1;
		ENABLE_WDT;
	}
	ADCCLRINTPNDNUP = 1;
}

int if_next(void)
{
	if(new_x - old_x > 500){
		return 1;
	}else if(old_x - new_x > 500){
		return 0;
	}else{
		return 2;
	}
}

void do_adc(void)
{
	static int i = 0;
	
	ADCCLRINT = 1;
	if(flag == 1){
		old_x = ADCDAT0 & 0xfff;
		flag = 0;
		i = 0;
	}else{
		val_x[i++] = ADCDAT0 & 0xfff;
		if(i == 10){
			i = 0;
		}
		new_x = cal_val(val_x, 10);
	}
	WAIT_UP;
}

int cal_val(int arr[], int n)
{
	int i;
	int sum = 0;

	for(i = 0; i < n; i++){
		sum += arr[i];
	}

	return sum / 10;
}

void change_pic(int n)
{
	static int index = 1;

        if(n == 1){
                index++;
                if(index == 5){
                        index = 0;
                }
        }else if(n == 0){
                index--;
                if(index < 0){
                        index = 4;
                }
        }
        VIDW00ADD0B0 = FRAME_BUF + index * 480 * 272 * 4;
}

