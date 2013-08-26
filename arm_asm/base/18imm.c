#include <stdio.h>

int main(int argc, char *argv[])
{
	__asm__ __volatile__(
		"data:\n"
		"movs r0, #0xf0000000\n"
		"ldr r1, [r0, #4]!\n"
		"ldr r1, [r0, #4]\n"
		"ldr r2, [r0], #4\n"
		"ldr r3, data\n"
		"mov r0, r0, lsr #4\n"
		"mov r0, r0, lsl #4\n"
		"mov r0, r0, asr #4\n"
		"mrs r0, cpsr\n"
		"msr cpsr, #10\n"
		"msr cpsr, r0\n"
	);

	return 0;
}
