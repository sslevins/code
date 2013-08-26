#include "regs.h"
#include "common.h"

void delay(int n);

int main(int argc, char *argv[])
{	
	int i = 0;

	led_init();
	while(1){	
		for(i = 0; i < 4; i++){
			led_on(i);
			delay(100);
			led_off(i);
		}
	}

	return 0;
}

void delay(int n)
{
	int i, j;

	for(i = 0; i < n; i++){
		for(j = 0; j < 1000; j++){
			;
		}	
	}
}
