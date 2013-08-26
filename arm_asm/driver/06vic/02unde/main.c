#include "regs.h"
#include "common.h"

int main(int argc, char *argv[])
{
	int cpsr;

	__asm__ __volatile__(
		"mrs r0, cpsr\n"
		"mov %0, r0\n"
		".word 0x77777777\n"
		:"=&r"(cpsr)
		:
		:"r0"
	);	

	printf("cpsr = %x\n", cpsr);
	
	return 0;
}

void do_unde(void)
{
	int cpsr;
 
	printf("in unde...\n");
         __asm__ __volatile__(
                 "mrs r0, cpsr\n"
                 "mov %0, r0\n"
                 :"=&r"(cpsr)
                 :
                 :"r0"
         );
        printf("cpsr = %x\n", cpsr);
	printf("out unde...\n");
}
