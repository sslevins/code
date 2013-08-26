#include <iostream>

class X
{
public:
	int i;
	X();
	~X();
	static int j;
	static void do_it();
	static void hello();
};

void X::hello()
{
	std::cout << X::j << std::endl;
}

int X::j = 0;

X::X()
{
	X::j++;
}

X::~X()
{
	X::j--;
}

void X::do_it()
{
	std::cout << "hello world" << std::endl;
}

int main()
{
	X a;
	a.i = 10; 	


	X b;
	b.i = 20;

	std::cout << X::j << std::endl;

	X::do_it();


	return 0;
}



