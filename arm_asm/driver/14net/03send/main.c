#include "regs.h"
#include "common.h"

void delay(void);

int main(void)
{
	eth_init();

	char buf[20] = {0x11, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0x10, 0x12};

	while(1){
		eth_send(buf, 12);
		delay();
	}	
	
	return 0;
}

void delay(void)
{
	int i, j;

	for(i = 0; i < 100; i++){
		for(j = 0; j < 10000; j++){
			;
		}	
	}
}
