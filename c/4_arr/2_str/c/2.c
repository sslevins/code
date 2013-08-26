#include <stdio.h>
#include <string.h>

void main()
{
	char str1[128] = "hello ";
	char str2[] = "world";

	strcat(str1, str2);

	puts(str1);
}

