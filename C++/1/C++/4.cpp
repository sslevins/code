#include <iostream>

class People 
{
	private:
		int count;
	
	public:
		int lend(int);
};

int People::lend(int _num)
{
	this->count = _num;
	std::cout << this->count << std::endl;

}

int main()
{
	People jim;

	jim.lend(100);
}










