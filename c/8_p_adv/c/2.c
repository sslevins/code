#include <stdio.h>

int i = 10;
int j = 100;

void do_it(int ** x)
{
	*x = &j;
}

void main()
{
	int* p;
	p = &i;
	do_it(&p);

	printf("%d\n", *p);
}


