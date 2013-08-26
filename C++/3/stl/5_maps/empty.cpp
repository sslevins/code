#include <iostream>
#include <map>

using namespace std;

int main()
{
	typedef map<int, char> M;

	M m1;
	
	if (m1.empty())
		cout << "empty" << endl;
	else
		cout << "not empty" << endl;
}



