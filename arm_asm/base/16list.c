#include <stdio.h>

int main(int argc, char *argv[])
{
	int flag = 0;
	
	__asm__ __volatile__(
		"list_create:\n"
		"sub sp, sp, #24\n"
		"mov r0, sp\n"

		"mov r1, #10\n"
		"str r1, [r0]\n"
		"add r1, r0, #8\n"
		"str r1, [r0, #4]\n"

		"mov r1, #20\n"
		"str r1, [r0, #8]\n"
		"add r1, r0, #16\n"
		"str r1, [r0, #12]\n"

		"mov r1, #30\n"
		"str r1, [r0, #16]\n"
		"mov r1, #0\n"
		"str r1, [r0, #20]\n"

		"list_find:\n"
		"mov r0, sp\n"
		"mov r1, #0\n"
		"again:\n"
		"ldr r2, [r0]\n"
		"cmp r2, r1\n"
		"moveq %0, #1\n"
		"beq end\n"
		"ldr r3, [r0, #4]\n"
		"cmp r3, #0\n"
		"beq end\n"
		"add r0, r0, #8\n"
		"b again\n"
		"\n"
		"end:\n"
		:"=&r"(flag)
	);
	printf("flag = %d\n", flag);
	
	return 0;
}
