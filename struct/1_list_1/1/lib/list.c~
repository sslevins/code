#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define NODE_SIZE sizeof(struct node)

struct node* malloc_node(int _data)
{
	struct node* node = (struct node *)malloc(NODE_SIZE);
	node->i = _data;
	node->next = NULL;
	printf("%#p\n", node);

	return node;
}

void free_node(struct node * _node)
{
	free(_node);
}

void add_node(struct node* _first_node, struct node* _node)
{
	struct node * cur = _first_node;

	while (cur->next != NULL)
		cur = cur->next;
	
	cur->next = _node;
}

void free_all_node(struct node* _node)
{
	if (_node == NULL)
		return ;

	free_all_node(_node->next);

	free(_node);
	//printf("%d ", _node->i);
}











