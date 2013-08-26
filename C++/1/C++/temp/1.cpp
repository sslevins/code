#include <iostrem>

typedef struct  {
		int i;
		int j;
} X;

void do_it(X * _x)
{
	printf("%d\n", _x->i);
}

struct Y
{
	int i;
	int j;
};



