#include <stdio.h>

struct node {
	int a;
};

struct hello
{
	char d;
	char e;
	char f;
	char g;
};

int main(int argc, char* argv[])
{
	struct node x;
	x.a = 100;

	struct hello* y = &x;
	printf("%d\n", y->d);


	return 0;
}

