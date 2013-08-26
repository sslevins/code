#include <stdio.h>
#include <stdlib.h>

struct A {
	int a;
	struct list_head head;
};

void main()
{

#define offsetof(type, member) \
	(unsigned int)&(((type *)0x0)->member)
  
#define containerof(ptr, type, member) \
	(type *)((char *)ptr - offsetof(type, member))

}

