#include <stdio.h>

void do_it(int _i)
{
	int i = 0;
	for (i = 2; i < _i; i++)
	{
		if (_i % i == 0)
			return ;
	}

	printf("%d ", _i);
}

void main()
{
	int i = 1;
	for (; i < 200; i++)
		do_it(i);
	printf("\n");
}
