#include <iostream>

class Y;

class X {
	private:
		int i;

	public:
		int j;
		// friend void do_it(X &);
		// friend void Y::getXI(X &);
		friend class Y;
};

class Y {
	public:
		void getXI(X &);
};

void Y::getXI(X & _x)
{
	std::cout << _x.i << std::endl;
}

int main()
{
	X a;
	a.j = 100;

	Y b;
	b.getXI(a);

}


