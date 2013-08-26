#include <stdio.h>

int main(void)
{
	int in = 10, out;

	__asm__ __volatile__(
		"mov r1, %[in]\n"
		"mov r0, r1\n"
		"mov %[out], r0\n"
		:[out]"=r"(out)
		:[in]"r"(in)
		:"r0", "r1"
	); 

	printf("out = %d\n", out);

	return 0;
}
