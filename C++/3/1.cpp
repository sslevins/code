#include <iostream>

using namespace std;

template <typename T>
T max(T& i, T& j)
{
	return i>j ? i : j;
}

template <typename X1, typename X2>
void do_it(X1 i, X2 j)
{
	cout << i << " " << j << endl;
}

template <typename T>
T sum(T i, T j, T k)
{
	T total = i+j+k;

	return total;
}

int main()
{
	do_it(19, 'a');
	do_it('a', 19);

	cout << sum(1, 2, 3) << endl;
	cout << sum(1.2, 3.4, 5.6) << endl;
}





