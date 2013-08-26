#include <iostream>

class A
{
	public:
		void do_it(void);
};

void A::do_it(void) {
	std::cout << "hello" << std::endl;
}

class B
{
	public:
		void do_it(void);
};

void B::do_it(void) {
	std::cout << "world" << std::endl;
}

class C : public A, public B
{

};

int main()
{
	C c;
	c.A::do_it();
	c.B::do_it();
}




