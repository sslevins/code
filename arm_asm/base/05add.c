#include <stdio.h>

int main(int argc, char *argv[])
{
	int sum = 0;
#if 0	
	__asm__ __volatile__(
		"mov r0, #10\n"
		"mov r1, #20\n"
		"add r0, r0, r1\n"
		"mov %0, r0\n"
		:"=&r"(sum)
		:
		:"r0", "r1"
	);

	printf("sum = %d\n", sum);
#endif
	int sumc = 0;

	__asm__ __volatile__(
		"mov r0, #1\n"
		"mvn r1, #0\n"
		"mov r2, #1\n"
		"add r0, r0, r1\n"
		"adc r2, r2, #1\n"
		"mov %0, r0\n"
		"mov %1, r2\n"
		:"=&r"(sum), "=&r"(sumc)
		:
		:"r0", "r1"
	);
	printf("sum = %d\n", sum);
	printf("sumc = %x\n", sumc);

	return 0;
}
