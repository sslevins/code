#include <stdio.h>

struct AA {
	int i;
	int j;

	void (*p)(void);
};

void do_it(void)
{
	printf("hello world!\n");
}


int main(int atgc, char* argv[])
{
	struct AA a;

	a.i = 10;
	a.j = 100;
	a.p = do_it;

	a.p();


	printf("%d\n", a.i);
	printf("%d\n", a.j);

}
