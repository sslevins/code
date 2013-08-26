#include <iostream>
#include <map>

using namespace std;

class A
{
public:
	bool operator()(int, int);
};

bool A::operator()(int a, int b)
{
	if (a > b)
		return true;
	else
		return false;
}

int main()
{
	map<int, char, A>  m;

	m.insert(make_pair(1, 'D'));
	m.insert(make_pair(2, 'C'));
	m.insert(make_pair(3, 'B'));
	m.insert(make_pair(4, 'A'));

	map<int, char, A>::iterator it = m.begin();

	while (it != m.end())
	{
		cout << (*it).first << ","; 
		cout << (*it).second << "\t";
		it++;
	}
	cout << endl;
}
