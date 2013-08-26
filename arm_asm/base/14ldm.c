#include <stdio.h>

int main(int argc, char *argv[])
{
	int out1, out2, out3, out4;

	__asm__ __volatile__(
		"mov r0, #1\n"
		"mov r1, #2\n"
		"mov r2, #3\n"
		"mov r3, #4\n"
		"stmfd sp!, {r0-r3}\n"
		"ldmfd sp!, {r4-r7}\n"
		"mov %0, r4\n"
		"mov %1, r5\n"
		"mov %2, r6\n"
		"mov %3, r7\n"
		:"=&r"(out1), "=&r"(out2), "=&r"(out3), "=&r"(out4)
		:
		:"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7"
	);
	printf("out1 = %d\n", out1);
	printf("out2 = %d\n", out2);
	printf("out3 = %d\n", out3);
	printf("out4 = %d\n", out4);

	return 0;
}
