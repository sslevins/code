#include <stdio.h>

int main(int argc, char *argv[])
{
	int cpsr;
	
	__asm__ __volatile__(
		"mrs r0, cpsr\n"
		"orr r0, r0, #0xf0000000\n"
		"msr cpsr, r0\n"
		"mrs %0, cpsr\n"
		:"=&r"(cpsr)
		:
		:"r0"
	);	
	printf("cpsr = %x\n", cpsr);
	
	return 0;
}
