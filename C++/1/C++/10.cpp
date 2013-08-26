#include <iostream>

class X {
	public:
		int * p;
		int i;
		int j;

		X();
		X(int*, int, int);
		X(X *);
};

X::X()
{
	this->p = NULL;
	this->i = 0;
	this->j = 0;
}


X::X(int* _p, int _i, int _j)
{
	this->p = _p;
	this->i = _i;
	this->j = _j;
}

X::X(X & _x)
{
	this->p = new int;
	*(this->p) = *(_x.p);
	this->i = _x.i;
	this->j = _x.j;
}

int main()
{
	int i = 9527;
	X a(&i, 10, 100);

	X b(a);

	std::cout << b.p << std::endl;
	std::cout << b.i << std::endl;
	std::cout << b.j << std::endl;

}
