#include <stdio.h>

struct XX {
	int i;
};

struct YY {
	int i; 		
	struct XX* aa;
};

void main()
{
	struct YY cc;
	cc.i = 10;

	// cc.aa->i = 100;
	struct XX* p = cc.aa;
	p->i = 100;
}



