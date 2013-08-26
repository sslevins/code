#include <iostream>

class X
{
	private:
		void do_it(int, int);
};

void do_it(int i)
{
	std::cout << i << " hello world" << std::endl;
}

void X::do_it(int i, int j)
{
	std::cout << i << " hello world" << std::endl;
	std::cout << j << " hello world" << std::endl;
}

int main()
{
	do_it(100);
}
