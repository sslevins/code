#include <stdio.h>

void do_it(void)
{
	static int i = 0;
	i++;
	printf("%d\n", i);
}

int main()
{
	do_it();
	do_it();
	do_it();
	do_it();
	do_it();
}

