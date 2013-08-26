#include <stdio.h>

int main(int argc, char *argv[])
{
	int sub = 0;
#if 0
	__asm__ __volatile__(
		"mov r0, #10\n"
		"mov r1, #5\n"
		"sub r0, r0, r1\n"
		"mov %0, r0\n"
		:"=&r"(sub)
		:
		:"r0", "r1"
	);

	printf("sub = %d\n", sub);
#endif
	int sbc = 0;

	__asm__ __volatile__(
		"mov r0, #0\n"
		"mov r1, #1\n"
		"mov r2, #5\n"
		"subs r0, r0, r1\n"
		"sbc r2, r2, #1\n"
		"mov %0, r0\n"
		"mov %1, r2\n"
		:"=&r"(sub), "=&r"(sbc)
		:
		:"r2", "r1", "r0"
	);
	printf("sub = %d\n", sub);
	printf("sbc = %d\n", sbc);

	return 0;
}
