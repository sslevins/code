#include <stdio.h>

static int i = 100;

static void do_it(void);


void do_it()
{
	static int i = 0;

	i++;

	printf("%d\n", i);
}
