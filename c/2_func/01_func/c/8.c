#include <stdio.h>

void do_it(int i)
{
	if (i == 0)
	{
		return;
	}

	do_it(i/2);
	printf("%d", i%2);
}

void main()
{
	int i = 129;

	printf("%08x\n", i);
	do_it(i);

	printf("\n");
}


