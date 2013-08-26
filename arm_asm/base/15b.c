#include <stdio.h>

int main(int argc, char *argv[])
{
	int out = 0;
#if 0
	__asm__ __volatile__(
		"mov %0, #1\n"
		"b end\n"
		"mov %0, #2\n"
		"end:\n"
		:"=&r"(out)
	);	
	printf("out = %d\n", out);
#endif
	__asm__ __volatile__(
		"mov r0, #1\n"
		"mov r1, #2\n"
		"mov r2, #3\n"
		"mov r3, #4\n"
		"bl add\n"
		"mov %0, r0\n"
		:"=&r"(out)
		:
		:"r0", "r1"
	);
	printf("out = %d\n", out);

	return 0;
}
#if 0
__asm__(
	"add:\n"
	"add r0, r0, r1\n"
	"mov pc, lr\n"
);
#endif
int add(int a, int b, int c, int d)
{
	return a + b + c + d;
}
