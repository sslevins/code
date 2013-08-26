#include <iostream>

class A
{
private:
	int i;

public:
	int j;
	void do_it(void);
};

void A::do_it(void)
{
	std::cout << this->i << std::endl;
	std::cout << this->j << std::endl;
}

//----------------------------------------

class B : public A
{

};

int main()
{
	B b;
	b.j = 100;
	b.do_it();
}





