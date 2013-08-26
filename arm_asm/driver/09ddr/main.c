#include "regs.h"
#include "common.h"

int main(int argc, char *argv[])
{
	char *ddr_p = (void *)0x54000000;
	char *string = "hello ddr...\n";
	
	WTCON = 0;	
	clock_init();
	uart_init();
	ddr_init();

	memcpy(ddr_p, string, 15);
	uputs(ddr_p);
	
	return 0;
}
