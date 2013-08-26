#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};

struct stack
{
	struct node* head_node;
};

struct stack * malloc_stack(void);
struct node * malloc_node(int);
void push(struct stack *, struct node *);
struct node * pop(struct stack *);
void stack_for_each(struct stack *, void (*)(struct node *));









