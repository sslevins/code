#include <stdio.h>

struct node {
	int i;
	char c;
	long long ll;
	float f;

	struct list_head;
};

struct list_head {
	struct list_head* prev;
	struct list_head* next;
};

struct queue {
	struct list_head* head_node;
};

struct queue * malloc_queue(void)
{}

void in_queue(struct list_head*)
{}

struct list_head* out_queue() 
{}
 
int main()
{
	struct node = malloc();
	in_queue(&(node_1.list_head)) // int queue




}






