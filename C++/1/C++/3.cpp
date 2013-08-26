#include <iostream>

class AA {
	public:
		int i;
		void do_it(void);

	private:
		int j;
};

void AA::do_it(void)
{
	std::cout << "hello world!\n" << std::endl;
}

int main(int atgc, char* argv[])
{
	AA a;

	a.i = 10;
	//a.j = 100;

	a.do_it();

	std::cout << a.i << std::endl;
	//std::cout << a.j << std::endl;
}
