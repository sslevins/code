#include <stdio.h>

int main(int argc, char *argv[])
{
	int mul = 0;

	__asm__ __volatile__(
		"mov r0, #5\n"
		"mov r1, #10\n"
		"mul %0, r0, r1\n"
		:"=&r"(mul)
		:
		:"r0", "r1"
	);

	printf("mul = %d\n", mul);

	return 0;
}
