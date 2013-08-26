#include <stdio.h>

extern void other(void);

void do_it(void)
{
	other();
	printf("%s\n", __FUNCTION__);
}
