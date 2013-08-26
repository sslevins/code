#include <iostream>

class A
{
public:
	int i;
	int j;
	int k;

	A();
	~A();
};

A::A()
{
	this->i = 100;
	this->j = 200;
	this->k = 300;
	std::cout << "A" << std::endl;
}

A::~A()
{
	std::cout << "~A" << std::endl;
}


// --------------------------------

class B : public A
{
public:
	int a;
	int b;
	int c;

	B();
	~B();
};

B::B()
{
	this->a = 10;
	this->b = 20;
	this->c = 30;
	std::cout << "B" << std::endl;
}

B::~B()
{
	std::cout << "~B" << std::endl;
}

int main()
{
	B b;

	return 0;
}







