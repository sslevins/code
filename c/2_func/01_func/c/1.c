#include <stdio.h>

void do_it(int i)
{
	printf("%d\n", i);
}

int add(int i, int j)
{
	int ret = i + j;

	return ret;
}

void main(void)
{
	do_it(10);

	int ret = add(10, 100);

	printf("the sum is %d\n", ret);
}




