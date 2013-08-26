#include <stdio.h>

int main(int argc, char *argv[])
{
	int and = 0, orr = 0, eor = 0, bic = 0, not = 0;

	__asm__ __volatile__(
		"mov r0, #0x5\n"
		"mov r1, #0x6\n"
		"and %0, r0, r1\n"
		"orr %1, r0, r1\n"
		"eor %2, r0, r1\n"
		"bic %3, r0, r1\n"
		:"=&r"(and), "=&r"(orr), "=&r"(eor), "=&r"(bic)
		:
		:"r0", "r1"
	);
	printf("and = %d\n", and);
	printf("orr = %d\n", orr);
	printf("eor = %d\n", eor);
	printf("bic = %d\n", bic);

	return 0;
}
