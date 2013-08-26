#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> a(10);

	for (int i = 0; i < 10; i++)
		a[i] = i;

	vector<int>::iterator it = a.begin();
	it++;
	
	a.insert(it, 3, 100);

	it = a.begin();
	while (it != a.end())
	{
		cout << *it << " ";
		it++;
	}
	
	cout << endl;
}



