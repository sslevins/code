#include "regs.h"
#include "common.h"

void do_recv(void);

int main(void)
{
	eth_init();
	
	GPNCON |= 2 << 14;
	EINT0CON0 |= 0x01 << 12;
	EINT0MASK &= ~(1 << 7);
	
	irq_request(1, do_recv);
	
	return 0;
}

void do_recv(void)
{
	char buf[2048];
	
	if(eth_recv(buf) > 0){
		printf(buf + 42);
	}
	
	EINT0PEND = EINT0PEND;
}
