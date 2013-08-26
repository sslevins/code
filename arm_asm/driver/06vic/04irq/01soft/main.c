#include "regs.h"
#include "common.h"

void delay(int n);
void irq_handle(void);

int main(int argc, char *argv[])
{
	irq_request(0, irq_handle);
	while(1){
		VIC0SOFTINT |= 1;
		delay(100);
	}

	return 0;
}

void irq_handle()
{
	printf("in irq...\n");
}

void delay(int n)
{
	int i, j;

	for(i = 0; i < n; i++){
		for(j = 0; j < 10000; j++){
			;
		}
	}
}
