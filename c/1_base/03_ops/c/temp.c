#include <stdio.h>

void main(void)
{
	int i;

	printf("Please input a date: ");
	scanf("%d", &i);

	printf("%d\n", i/7+1);
	printf("%d\n", i%7);

}
