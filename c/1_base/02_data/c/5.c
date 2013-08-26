#include <stdio.h>

void main(void)
{
	int i = 0xffffffff;
	unsigned int j = 0xffffffff;

	//printf("%d\n", i);
	//printf("%u\n", j);

	printf("%u\n", j+1);

	i = 0x7fffffff;
	printf("%d\n", i+1);

}




