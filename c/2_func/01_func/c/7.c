#include <stdio.h>

int do_it(int i)
{
	if (i == 1)
	{
		return 1;
	}

	return i*do_it(i-1);
}

void main()
{
	int i = 0;
	while (++i < 15)
	{
		printf("%d!: %d\n", i, do_it(i));
	}
}

