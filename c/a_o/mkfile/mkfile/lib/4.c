#include <stdio.h>

extern printf_3(void);

void printf_4(void)
{
	printf_3();

	printf("4\n");
}
