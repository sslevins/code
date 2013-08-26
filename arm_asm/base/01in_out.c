#include <stdio.h>

int main(void)
{
	int in = 10, out;

	__asm__ __volatile__(
		"mov r1, %1\n"
		"mov r0, r1\n"
		"mov %0, r0\n"
		:"=r"(out)
		:"r"(in)
		:"r0", "r1"
	); 

	printf("out = %d\n", out);

	return 0;
}
