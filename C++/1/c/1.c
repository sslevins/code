#include <stdio.h>

typedef struct {
	char name[128];
	unsigned int age;
	unsigned int hungry;
	unsigned int weight;

	void (*catchMouse)(Cat *, Mouse *);
} Cat;

typedef struct {
	char name[128];
	unsigned int age;
	unsigned weight;
} Mouse;

void __catchMouse(Cat * _cat, Mouse * _mouse)
{
	int temp;
	if (_cat.hungry <= 60)
	{
		if (temp % 2 == 0)
			return ;
	}

	_cat.hungry += 10;
	_cat.weight += (_mouse.weight / 70); 
	
	free(_mouse);
}

void main()
{
	Cat * cat = (Cat *) malloc(sizeof(Cat));
	Mouse * mouse = (Mouse *) malloc(sizeof(Mouse));

	mouse.age = 1;
	mouse.weight = 100;

	cat.age = 3;
	cat.weight = 1000;
	cat.catchMouse = __catchMouse;

	cat.catchMouse(cat, mouse);
}





