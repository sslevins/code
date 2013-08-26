#include <iostream>

class A
{
public:
	int j;
	A();
	A(int, int);
	void do_it(void);

private:
	int i;
};

A::A()
{}

A::A(int _i, int _j)
{
	this->i = _i;
	this->j = _j;
}

void A::do_it(void)
{
	std::cout << "hello world" << std::endl;
}

class B
{
public:
	int a;
	int b;
	virtual void say_hello(void) = 0;
	virtual void say_bye(void) = 0;
};

class C : public A, public B
{
public:
	C();
	void say_hello(void);
	void say_bye(void);
};

C::C()
{
}

void C::say_hello(void)
{
	std::cout << "hello" << std::endl;
}

void C::say_bye(void)
{
	std::cout << "bye" << std::endl;
}

int main()
{
	B* b = new C;

	b->say_hello();
	b->say_bye();
}





