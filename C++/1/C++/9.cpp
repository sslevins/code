#include <iostream>
#include <stdio.h>

class X
{
	public:
		int i;
		int j;
		X();
		X(int, int);
		X(int, int, char *);
		~X();
};

X::X()
{
	this->i = 10;
	this->j = 100;
}

X::X(int a, int b)
{
	this->i = a;
	this->j = b;
}

X::X(int a, int b, char* c)
{
	this->i = a;
	this->j = b;
	printf("%s\n", c);
}

X::~X()
{
	printf("goodbye\n");
}


int main()
{
	//int i = 10;
	//int j(100);
	
	X x(200, 300, "hello world!");

	X* y = new X;
	// X* y = (X *)malloc(sizeof(X));

	std::cout << x.i << std::endl;
	std::cout << x.j << std::endl;

	std::cout << y->i << std::endl;
	std::cout << y->j << std::endl;
}


