#include <stdio.h>
#include "2.h"

extern printf_1(void);

void printf_2(void)
{
	printf_1();
	printf("%d\n", var_2);
}
