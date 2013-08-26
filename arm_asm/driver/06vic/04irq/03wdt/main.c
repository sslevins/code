#include "regs.h"
#include "common.h"

void delay(int n);
void irq_handle(void);

int main(int argc, char *argv[])
{
	wdt_init(1000);
	irq_request(26, irq_handle);

	return 0;
}

void irq_handle(void)
{
	printf("wdt is here...\n");
	WTCLRINT = 1;
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
