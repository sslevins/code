#include <iostream>
#include <list>

using namespace std;

bool func1(int i)
{
	if (i == 2)
		return true;
	else
		return false;
}

bool func2(int i, int j)
{
	//if (i % 2 == 0 && j % 2 == 0)
	if (j == 4 || j == 10)
		return true;
	else
		return false;
}

int main()
{
	list<int> a(1, 12);
	a.push_back(11);
	a.push_back(10);
	a.push_back(8);
	a.push_back(6);
	a.push_back(4);
	a.push_back(2);

	list<int>::iterator it = a.begin();

	while (it != a.end())
	{
		cout << *it << " ";
		it++;
	}

	cout << endl;

	//a.push_back(2);
	//a.remove(2);
	//a.remove_if(func);
	
	// a.unique();
	// a.unique(func2);
	a.sort();

	it = a.begin();
	while (it != a.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}
