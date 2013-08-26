#include <stdio.h>

void main()
{
	int i = 10;
	printf("%d\n", i);
	i++;
	printf("%d\n", i);

	printf("\n-----\n\n");

	int* p = &i;
	printf("%p\n", p);
	p++;
	printf("%p\n", p);


