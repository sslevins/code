#include <stdio.h>

int sum(int i, int j)
{
	int ret = i + j;

	return ret;
}

void main(void)
{
	int total = sum(10, 100);

	printf("%d\n", total);
}
