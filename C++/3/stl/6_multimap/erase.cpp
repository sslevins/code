#include <iostream>
#include <map>

using namespace std;

int main()
{
	typedef multimap<int, char, less<int> > M;	
	M m1;

	m1.insert(make_pair(2, 'B'));
	m1.insert(make_pair(3, 'C'));
	m1.insert(make_pair(1, 'A'));
	m1.insert(make_pair(1, 'a'));

	M::iterator It = m1.begin();
	cout << endl << "m1:" << endl;
	while (It != m1.end())
	{
		cout << (*It).first << " - " << (*It).second << endl;
		It++;
	}

	m1.erase(1);

	It = m1.begin();
	cout << endl << "m1:" << endl;
	while (It != m1.end())
	{
		cout << (*It).first << " - " << (*It).second << endl;
		It++;
	}
}
