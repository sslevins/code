#include <iostream>

class A
{
	public:
		virtual void do_it(void) = 0;
};

void A::do_it(void)
{
	std::cout << "hello world" << std::endl;
}

int main()
{
	A a;
	new A;
	
	a.do_it();
}





