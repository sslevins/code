#include "regs.h"
#include "common.h"

void delay(int n);

int main(int argc, char *argv[])
{	
	int i = 0;

	led_init();
	clock_init();
	while(1){	
		led_on(i);
		delay(100);
		led_off(i);
		i++;
		if(i == 4){
			i = 0;
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
