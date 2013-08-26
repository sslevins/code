#include <iostream>

class A
{
public:
	int i;
	A();
	A(int);
	~A();

	void do_it(void);
};

A::A()
{
	this->i = 0;
}

A::A(int _i)
{
	this->i = _i;
}

A::~A()
{

}

void A::do_it(void)
{
	std::cout << "hello world" << std::endl;
}

// ----------------------------------------------------

class B : public A
{
public:
	int j;
	B();
	B(int, int);
	~B();

	void do_it(void);

};

B::B()
{
	this->j = 0;
}

B::B(int _i, int _j) : A(_i), j(_j)
{
	// this->i = _i;
	// this->j = _j;
}

B::~B()
{

}

void B::do_it(void)
{
	std::cout << "goodbye" << std::endl;
}

int main()
{
	B b(10, 20);

	b.do_it();

	return 0;
}




