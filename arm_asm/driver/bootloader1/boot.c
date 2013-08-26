#include "regs.h"

void arm_boot(void)
{
	int *ddr_p = (void *)0x57000000;
	
	WTCON = 0;

	__asm__ __volatile__(
		"mrs r0, cpsr\n"
		"bic r0, r0, #0xc0\n"
		"msr cpsr, r0\n"	
		:
		:
		:"r0"
	);

	clock_init();
	ddr_init();
	nand_init();
	led_init();

	nand_read(ddr_p, 0, 0x40000);

	__asm__ __volatile__(
		"mov sp, #0x58000000\n"
		"mov lr, pc\n"
		"ldr pc, =main\n"
		"there:\n"
		"b there\n"
	);
}
