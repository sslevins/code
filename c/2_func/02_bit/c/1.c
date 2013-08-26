#include <stdio.h>

void main(void)
{
	int i = 0xff00ff00;
	int j = ~i;

	printf("%08x\n", i);
	printf("%08x\n", j);
}


