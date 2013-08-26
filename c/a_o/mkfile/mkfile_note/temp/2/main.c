#include <stdio.h>

extern void do_it(void);

void main()
{
	do_it();
	printf("hello world\n");
	printf("%s\n", __FUNCTION__);
}
