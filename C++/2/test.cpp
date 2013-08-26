#include <iostream>

using namespace std;

class X
{
public:
	static int i;
};

int X::i = 10;

class Y
{
public:
	static int i;
};

int Y::i = 100;

int main()
{
	cout << X::i << endl;
	cout << Y::i << endl;
	return 0;
}




