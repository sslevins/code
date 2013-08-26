#include <stdio.h>

void do_it(char);

void main()
{
	do_it('a');

	printf("\n");
}

void do_it(char c)
{
	if (c > 'e')
	{
		return;
	}

	printf("%c+", c);

	int x = c+1;
	do_it(x);

	printf("%c-", c);
}



