#include <stdio.h>

void do_it(char* p)
{
	int i = 0;

	while (*p != '\0')
	{
		if (*p == '%')
			i++;
		p++;
	}

	printf("%d\n", i);
}

void main()
{
	do_it("%d %d \n");
}

