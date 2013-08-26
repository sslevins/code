#include <iostream>

void swap(int & a, int & b)
{
	std::cout << &a << std::endl;
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int i = 100;
	int j = 10000;
	std::cout << &i << std::endl;

	swap(i, j);

	std::cout << i << std::endl;
	std::cout << j << std::endl;


	int & x = i;
	int * p = &i;

}


