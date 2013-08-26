#include <stdio.h>

void main()
{
	char buf[128] = {0};

	gets(buf);

	char* p = buf;

	while (*p != ' ')
	{
		p++;
	}

	*p='\0';

	printf("%s\n", buf);
}
