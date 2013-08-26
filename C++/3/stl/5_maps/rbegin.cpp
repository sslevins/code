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

	M::reverse_iterator It = m1.rbegin();

	cout << endl << "m1: " << endl;
	while (It != m1.rend())
	{
		cout << (*It).first << " - " << (*It).second << endl;
		It++;
	}

}



