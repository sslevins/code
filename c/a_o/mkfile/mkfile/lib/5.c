#include <stdio.h>

extern printf_4(void);

void printf_5(void)
{
	printf_4();
	printf("5\n");
}
