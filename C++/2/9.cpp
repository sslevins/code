#include <iostream>

class X
{
public:
	int i;
	int j;
	void do_it(void);
	X & operator+(X &);
	bool operator==(X &);
};

bool X::operator==(X & _x)
{
	if (this->i == _x.i && 
		this->j == _x.j)
		return true;
	else
		return false;
}

X X::operator+(X & _x)
{
	X ret;
	ret->i = this->i + _x.i;
	ret->j = this->j + _x.j;

	return ret;
}

int main()
{
	X a; a.i = 10; a.j = 100;
	X b; b.i = 20; b.j = 200;

	X c = a+b;
	std::cout << c.i << std::endl;
	std::cout << c.j << std::endl;
}
