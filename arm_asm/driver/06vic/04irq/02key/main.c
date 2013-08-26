#include "regs.h"
#include "common.h"

void delay(int n);
void irq_handle(void);

int main(int argc, char *argv[])
{
	GPNCON &= ~0xff;
	GPNCON |= 0xaa;

	EINT0CON0 &= ~0xff;
	EINT0CON0 |= 0x22;

	EINT0MASK &= ~0xf;

	irq_request(0, irq_handle);

	return 0;
}

void irq_handle(void)
{
	switch(EINT0PEND & 0xf){
		case 1:
			printf("key_0 is down\n");
			break;
		case 2:
			printf("key_1 is down\n");
			break;
		case 4:
			printf("key_2 is down\n");
			break;
		case 8:
			printf("key_3 is down\n");
			break;
		default:
			printf("no key\n");
			break;
	}

	EINT0PEND = EINT0PEND;
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
