#include <stdio.h>

int main(void)
{
	int in_out = 10, out;

	__asm__ __volatile__(
		"mov %1, %0\n"
		"mov %0, #20\n"
		:"+r"(in_out), "=r"(out)
	); 

	printf("in_out = %d\n", in_out);
	printf("out = %d\n", out);

	return 0;
}
