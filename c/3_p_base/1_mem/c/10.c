#include <stdio.h>
#include <string.h>

int do_it(char* p)
{
	int len = 0;
	while (*p++ != '\0')
	{
		len++;
		//p++;
	}

	return len;
}

void main()
{
	char* p = "hello world";

	printf("%s\n", p);

	printf("%d\n", strlen(p));
	printf("%d\n", do_it(p));
}

