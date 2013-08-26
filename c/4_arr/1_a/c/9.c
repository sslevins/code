#include <stdio.h>

void main()
{
	int i = 0x12345678;

	int* p = &i;
	char* q = (char *)&i;

	printf("%p\n", p);
	printf("%p\n", q);

	printf("%08x\n", *p);
	printf("%08x\n", *q);
}

