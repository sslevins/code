#include <stdio.h>

int main(int argc, char *argv[])
{
	int in1 = 0, in2 = 0, in3 = 0;
	int out1, out2, out3;

	__asm__ __volatile__(
		"mov r3, %3\n"
		"mov r4, %4\n"
		"mov r5, %5\n"

		"mov %0, r3\n"
		"mov %1, r4\n"
		"mov %2, r5\n"
		:"=&r"(out1), "=&r"(out2), "=&r"(out3)
		:"r"(in1), "r"(in2), "r"(in3)
		:"r3", "r4", "r5"
	);
	
	return 0;
}
