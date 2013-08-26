#include <stdio.h>

void hello(void)
{
	printf("hello world\n");
}

void (*)(void) do_it(void)
{
	return hello;
}

void main()
{
	void (*p)(void) = do_it();

	p();
}


