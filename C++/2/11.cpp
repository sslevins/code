#include <iostream>

namespace X {
	int i = 10;
};

namespace Y {
	int i = 100;
};

using namespace std;

int main()
{
	cout << X::i << endl;
	cout << Y::i << endl;
}




