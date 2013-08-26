#include <iostream>

class X;
class Y;

void Y::getXI(X *);

class X
{
	private:
		int i;
	
	public:
		void setI(int);

		friend void do_it(X *);
		friend void Y::getXI(X *);
};

class Y
{
	public:
		void getXI(X *);
};

void Y::getXI(X * _x)
{
	std::cout << _x->i << std::endl;
}

void do_it(X * _x)
{
	std::cout << _x->i << std::endl;
}

void X::setI(int _num)
{
	this->i = _num;
}

int main()
{
	X a;
	a.setI(100);
	do_it(&a);
}
