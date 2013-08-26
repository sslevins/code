#include <stdio.h>
#include "3.h"

extern printf_2(void);

void printf_3(void)
{
	printf_2();
	printf("%d\n", var_3);
}
