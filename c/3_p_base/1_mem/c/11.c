#include <stdio.h>

void main()
{
	char arr[] = "xxxxxxxxxxxx";
	arr[5] = '\0';
	char* p = arr;

	while (*p != '\0')
	{
		p++;
	}

	printf("%c\n", *p);
}


