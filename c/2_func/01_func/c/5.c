#include <stdio.h>

int sum(int, int, int);

void sum(int, int, int);

void main()
{
	printf("%d\n", sum(1, 10, 100));
}

int sum(int i, int j, int k)
{
	return i+j+k;
}

void sum(int i, int j, int k)
{
	printf("hello world\n");
}



