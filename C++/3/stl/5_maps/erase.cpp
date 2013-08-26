#include <iostream>
#include <map>

using namespace std;

int main()
{
	typedef map<int, char, less<int> > M;
	
	// 1	
	M m1;
	m1.insert(make_pair(2, 'B'));
	m1.insert(make_pair(3, 'C'));
	m1.insert(make_pair(1, 'A'));

	M::iterator It = m1.begin();

	cout << endl << "m1: " << endl;
	while (It != m1.end())
	{
		cout << (*It).first << " - " << (*It).second << endl;
		It++;
	}

	m1.erase(3);

	It = m1.begin();
	cout << endl << "m1: " << endl;
	while (It != m1.end())
	{
		cout << (*It).first << " - " << (*It).second << endl;
		It++;
	}

}



