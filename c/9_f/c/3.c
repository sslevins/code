#include <stdio.h>

void main()
{
	int i = 100;
	printf("hello world %d\n", i);
	fprintf(stdout, "hello world %d\n", i);

	scanf("%d", &i);
	fscanf(stdin, "%d", &i);
}
