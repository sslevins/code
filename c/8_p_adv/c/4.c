#include <stdio.h>

void main()
{
	const int i = 100;

	// i = 1000;
	int* p = &i;
	*p = 1000;

	printf("%d\n", i);
}
