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

	M m2(m1);
	It = m2.begin();
	cout << endl << "m2:" << endl;
	while (It != m2.end())
	{
		cout << (*It).first << " - " << (*It).second << endl;
		It++;
	}

	M m3(m2.begin(), m2.end());
	It = m3.begin();
	cout << endl << "m3:" << endl;
	while (It != m3.end())
	{
		cout << (*It).first << " - " << (*It).second << endl;
		It++;
	}
}
