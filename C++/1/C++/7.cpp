#include <iostream>

class X {
	private:
		int i;
	public:
		void setI(int);
};

class Y {
	private:
		int i;
	public:
		void setI(int);
};

void do_it();
{
	std::cout << "hello world!" << std::endl;
}

void X::setI(int _num)
{
	this->i = _num;
}

void Y::setI(int _num)
{
	this->i = _num;
}



