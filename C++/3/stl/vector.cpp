#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
	int i;
	int j;
};

int main()
{
	vector<A> a(10);
	for (int i = 0; i < 10; i++)
	{
		a[i].i = i;
		a[i].j = i*10;
	}

	vector<A>::iterator it = a.begin();
	// while (it != a.end())
	for (it = a.begin(); it != a.end(); it++)
	{
		cout << (*it).i <<" ";
		//it++;
	}
	cout << endl;

	vector<A>::reverse_iterator rit = a.rbegin();
	while (rit != a.rend())
	{
		cout << (*rit).j << " ";
		rit++;
	}

	cout << endl;



}



