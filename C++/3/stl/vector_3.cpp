#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> a(10);
	for (int i = 0; i < 10; i++)
		a[i] = i;
	cout << a[0] << endl;

	cout << "size:\t" << a.size() << endl;
	cout << "max_size:\t" << a.max_size() << endl;

	if (a.empty())
		cout << "a is empty" << endl;
	else
		cout << "a is not empty" << endl;
}



