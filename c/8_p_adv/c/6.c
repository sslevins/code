#include <stdio.h>

void sum(int, int);

int main()
{
	int (*p)(int, int, int) = (int (*)(int, int, int))sum;

	sum(2, 3);

	return 0;
}

void sum(int i, int j)
{
	printf("%d\n", i+j);
}

