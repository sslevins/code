#include <iostream>

class A
{
private:
	int i;

protected:
	int j;

public:
	int k;
};

//----------------------------------------
/*
class B : public A
{
protected:
	int j;
public:
	int k;
};
*/

class B : private A
{
private:
	int j;
	int k;
};

int main()
{
	B b;
	//b.i = 100;
	//b.j = 100;
	//b.k = 100;
	b.do_it();
}





