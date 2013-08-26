#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> a(10);
	for (int i = 0; i < 10; i++)
		a[i] = i;
	cout << a[0] << endl;

	vector<int> b(10);
	for (int i = 0; i < 10; i++)
		b[i] = 10-i;

	a.swap(b);

	cout << a[0] << endl;

	cout << "at 1 " << a.at(1) << endl;
	cout << "front " << a.front() << endl;
	cout << "back " << a.back() << endl;
}



