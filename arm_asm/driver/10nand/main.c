#include "regs.h"
#include "common.h"

int main(int argc, char *argv[])
{
	int i = 0;
	char *p=(void *)0x52000000;
	char *buf=(void *)0x51000000;
	WTCON=0;
	clock_init();
	uart_init();
	ddr_init();
	nand_init();

	memcpy(buf,"helloworld\n",12);
	memset(p,0,12);
	nand_erase(0x200000,12);
	nand_write(buf,0x200000,12);
	nand_read(p,0x200000,12);
	uprintf(p);
	uprintf("\n");
	return 0;
}
