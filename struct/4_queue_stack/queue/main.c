#include <stdio.h>

#include "queue.h"

void print_queue(struct node * _node)
{
	printf("%d ", _node->data);
}

void main()
{
	struct queue* queue = malloc_queue();

	struct node* node = NULL;

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		node = malloc_node(i);
		in_queue(queue, node);
	}
	queue_for_each(queue, print_queue);
	printf("\n");

	for (i = 0; i < 5; i++)
		out_queue(queue);

	queue_for_each(queue, print_queue);
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		node = malloc_node(i);
		in_queue(queue, node);
	}

	queue_for_each(queue, print_queue);
	printf("\n");
}

