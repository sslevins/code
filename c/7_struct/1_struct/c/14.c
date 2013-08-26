#include <stdio.h>

struct x 
{
	int i;
	int j;
	int k;
};

void main()
{
	struct x hello;

	struct x* temp;
	temp = &hello;

	temp->i = 0x1000;
	temp->j = 0x2000;
	temp->k = 0x3000;
}

