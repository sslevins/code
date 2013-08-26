#include <iostream>

class A
{
public:
	void operator()(void);
};

void A::operator()(void)
{
	std::cout << "hello world!" << std::endl;
}

int main()
{
	A a; 	a(); // a++;
	A b; 	b();
	A c; 	c();
	A d; 	d();

}


