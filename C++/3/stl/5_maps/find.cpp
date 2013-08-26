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

	It = m1.find(2);
	if (It != m1.end())
		cout << "key 2 has value " << (*It).second << endl;
	else
		cout << "key 2 not found" << endl;
}



