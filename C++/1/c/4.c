#include <stdio.h>

struct X {
	int i;
	void (*setX)(struct X *, int);
};

void __setX(struct X * _x, int _i)
{
	_x->i = _i;
}

void main()
{
	struct X a;
								a.setX = __setX;
	a.setX(&a, 10);

	struct X b;
								b.setX = __setX;
	b.setX(&b, 10);

}

