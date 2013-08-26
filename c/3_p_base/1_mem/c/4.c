#include <stdio.h>

void main()
{
	int i = 10;

	int* p = &i;
	int* q = 0x1000;

	printf("1: %p\n", p);
	printf("2: %p\n", q);

	printf("3: %d\n", *p);
	printf("4: %d\n", *q);

}

