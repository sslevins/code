#include <stdio.h>

int main(int argc, char *argv[])
{
	int lsr = 0, lsl = 0, ror = 0, asr = 0, alsr = 0;

	__asm__ __volatile__(
		"mov r0, #0xf0\n"
		"mov r1, #-10\n"
		"mov %0, r0, lsr #1\n"
		"mov %1, r0, lsl #1\n"
		"mov %2, r0, ror #8\n"
		"mov %3, r1, asr #1\n"
		"mov %4, r1, lsr #1\n"
		:"=&r"(lsr), "=&r"(lsl), "=&r"(ror), "=&r"(asr), "=&r"(alsr)
		:
		:"r0", "r1"
	);
	printf("lsr = %x\n", lsr);
	printf("lsl = %x\n", lsl);
	printf("ror = %x\n", ror);
	printf("asr = %d\n", asr);
	printf("alsr = %d\n", alsr);

	return 0;
}
