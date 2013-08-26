#include <iostream>

template <typename T, typename Tx>
class A {
public:
	T i;
	Tx j;

	A();
	A(T, Tx);
};

template <typename T, typename Tx>
A<T, Tx>::A()
{
	std::cout << "ouch" << std::endl;
}

template <typename T, typename Tx>
A<T, Tx>::A(T i, Tx j)
{
	this->i = i;
	this->j = j;
}

int main()
{
	A<int, long> a(1, 2);

	A<long, int> b(3, 4);
}
