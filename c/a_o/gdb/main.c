#include <stdio.h>

void do_it(void)
{
	int i = 0;
	int j = 0;

	for (; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
			printf("%d ", i*j);

		printf("\n");
	}
}

void main()
{
	do_it();
}
