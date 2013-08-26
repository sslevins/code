#include "regs.h"
#include "common.h"

void delay(int n);

int main(int argc, char *argv[])
{	
	key_init();	
	led_init();
	while(1){
		switch(GPNDAT & 0xf){
			case 0xe:
				led_on(0);
				printf("key 0 is down...\n");
				break;
			case 0xd:
				led_on(1);
				printf("key 1 is down...\n");
				break;
			case 0xb:
				led_on(2);
				printf("key 2 is down...\n");
				break;
			case 0x7:
				led_on(3);
				printf("key 3 is down...\n");
				break;
			default:
				led_off(0);
				led_off(1);
				led_off(2);
				led_off(3);
				printf("no key is down...\n");
				break;
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
