#include <stdio.h>

void main(void)
{
	int a = 10;
	unsigned int b = 10;

	short c = 10;
	unsigned short d = 10;

	long e = 100;
	unsigned long f = 1000;

	long long g = 1000;
	unsigned long long h = 1000;

	int size;

	size = sizeof(int);
	printf("int: %d\n", size);

	size = sizeof(unsigned int);
	printf("unsigned int: %d\n", size);

	size = sizeof(short);
	printf("short: %d\n", size);

	size = sizeof(unsigned short);
	printf("unsigned short: %d\n", size);

	size = sizeof(long);
	printf("long: %d\n", size);

	size = sizeof(unsigned long);
	printf("unsigned long: %d\n", size);

	size = sizeof(long long);
	printf("long long: %d\n", size);

	size = sizeof(unsigned long long);
	printf("unsigned long long: %d\n", size);
}





