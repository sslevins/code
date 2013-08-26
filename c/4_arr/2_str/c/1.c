#include <stdio.h>
#include <string.h>

void main()
{
	char buf[1024] = {0};

	printf("Please input a string: ");
	gets(buf);

	//printf("you just input: %s\n", buf);
	puts("you just input: ");
	puts(buf);
}
