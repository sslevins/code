#include <iostream>

template <typename T>
class A
{
public:
	T i;
	A * next;
};

int main()
{
	A<int> a;

	A<int> * p = new A<int>;
}



