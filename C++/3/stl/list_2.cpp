#include <iostream>
#include <list>

using namespace std;

class A
{
public:
	int i;
	int j;
	int k;
	A(int, int, int);
};

A::A(int _i, int _j, int _k)
{
	this->i = _i;
	this->j = _j;
	this->k = _k;
}

bool op(A* a, A* b)
{
	if (a->j < b->j)
		return true;
	else
		return false;
}

int main()
{
	list<A*> a(1, new A(1, 9, 0));
	a.push_back(new A(2, 8, 0));
	a.push_back(new A(3, 7, 0));
	a.push_back(new A(4, 6, 0));
	a.push_back(new A(5, 5, 0));
	a.push_back(new A(6, 4, 0));
	a.push_back(new A(7, 3, 0));
	a.push_back(new A(8, 2, 0));
	a.push_back(new A(9, 1, 0));

	list<A*>::iterator it = a.begin();

	while (it != a.end())
	{
		cout << "(" << (*it)->i << " ";
		cout << (*it)->j << ") ";
		it++;
	}

	cout << endl;

	a.sort(op);

	it = a.begin();
	while (it != a.end())
	{
		cout << "(" << (*it)->i << " ";
		cout << (*it)->j << ") ";
		it++;
	}
	cout << endl;

}
