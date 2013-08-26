#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node* prev;
	struct node* next;
};

struct queue
{
	struct node* head_node;
};

struct queue* malloc_queue(void);
struct node* malloc_node(int);
void in_queue(struct queue*, struct node*);
struct node* out_queue(struct queue *);
void queue_for_each(struct queue *, void (*)(struct node *));




