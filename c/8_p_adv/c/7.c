#include <stdio.h>

void say_hello()
{
	printf("hello world\n");
}

void say_goodbye()
{
	printf("goodbye\n");
}

void do_it(void (*p)(void))
{
	p();
}

void main()
{
	char c;

	printf("please input a or b\n");
	scanf("%c", &c);

	if (c == 'a')
		do_it(say_hello);
	else
		do_it(say_goodbye);
}

