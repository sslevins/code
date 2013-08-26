#include <iostream>

class X
{
	public:
		int i;
		void print_i(X *);
};

void X::print_i(X * _this)
{
	std::cout << _this << std::endl;
}

int main()
{
	X a; 		a.i = 10;
	X b; 		b.i = 100;
	X c; 		c.i = 1000;

	std::cout << &a << " ";
	a.print_i(&a);

	std::cout << &b << " ";
	b.print_i(&b);

	std::cout << &c << " ";
	c.print_i(&c);
}
