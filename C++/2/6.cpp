#include <iostream>

class A
{
public:
	virtual void do_it(void);
};

void A::do_it(void)
{
	std::cout << "hello world" << std::endl;
}

class B : public A
{
public:
	void do_it(void);
	void hello(void);
};

void B::do_it(void)
{
	std::cout << "goodbye" << std::endl;
}

void B::hello(void)
{
	std::cout << "xxxx" << std::endl;
}

int main()
{
	A* a = new B;
	a->do_it();
	a->hello();

	return 0;
}




