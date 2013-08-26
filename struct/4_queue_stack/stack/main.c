#include <stdio.h>

#include "stack.h"

void print_node(struct node * cur)
{
	printf("%d ", cur->data);
}

void main()
{
	struct stack * stack = malloc_stack();

	struct node * node = NULL;
	struct node * ret = NULL;

	node = malloc_node(1);	push(stack, node);
	node = malloc_node(2);	push(stack, node);

	ret = pop(stack); printf("%d ", ret->data);
	ret = pop(stack); printf("%d ", ret->data);

	node = malloc_node(3);	push(stack, node);

	ret = pop(stack); printf("%d ", ret->data);



	printf("\n");
}



