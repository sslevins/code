#include <stdio.h>

int main(int argc, char *argv[])
{
	int flag = 0;

	__asm__ __volatile__(
		"mov r0, #9\n"
		"mov r1, #8\n"
		"cmp r0, r1\n"
		"movgt %0, #1\n"
		"movlt %0, #2\n"
		"moveq %0, #3\n"
		:"=&r"(flag)
		:
		:"r0", "r1"
	);
	printf("flag = %d\n", flag);

	return 0;
}
