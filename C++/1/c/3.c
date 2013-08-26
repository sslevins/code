#include <stdio.h>

struct People
{
	int count;

	int (*lend)(int);
};

int __len(struct People * p, int _num)
{
	if (p->count < _num)
		return 0;
	
	if (p->count < 50)
		return 0;
	
	p->count -= _num;

	return _num;
}

void main()
{
	struct People jim;
	jim.count = 40;
	jim.lend = __len;

	struct People tom;
	tom.count = 100;


	int num = jim.lend(jim, 10);
	tom.count += num;

	if (num == 0 && jim.count > 10)
		printf("tom say: fuck\n");
}

