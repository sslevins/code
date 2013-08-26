#include <stdio.h>
#include <stdlib.h>

#define offsetof(type, member) \
	(unsigned int)&(((type *)0x0)->member)

struct list_head
{
	struct list_head* prev;
	struct lsit_head* next;
};

struct node
{
	int data;
	struct list_head xx;
};

void main()
{
	struct node * node = (struct node *) malloc(sizeof(struct node));

	node->data = 10;
	node->xx.prev = NULL;
	node->xx.next = NULL;

	struct list_head* hello = &(node->xx);
	
	printf("%p\n", node);
	printf("%p\n", (unsigned int)hello - (unsigned int)&(((struct node*)0x0)->xx));

	printf("offset: %d\n", offsetof(struct node, xx));

#define offsetof(type, member) \
	(unsigned int)&(((type *)0x0)->member)

#define containerof(ptr, type, member) \
	(type *)((char *)ptr - offsetof(type, member))

	struct node* world = containerof(hello, struct node, xx)
	
}



