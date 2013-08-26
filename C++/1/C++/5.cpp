#include <iostream>

class X
{
	public:
		int i;
		void setX(int);
};

void X::setX(int _num)
{
	this->i = _num;
}

int main()
{
	X a;
	a.setX(10);		// (&a)->i = 10;

	X b;
	b.setX(100);	// (&b)->i = 10;
}





