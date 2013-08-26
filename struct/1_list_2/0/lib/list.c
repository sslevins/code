#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define NODE_SIZE sizeof(struct node)
#define LIST_SIZE sizeof(struct list)

struct list* malloc_list(void)
{
	struct node * node = (struct node *) malloc(NODE_SIZE);
	node->i = 0;
	node->next = NULL;

	struct list* list = (struct list *)malloc(LIST_SIZE);
	list->head_node = node;

	return list;
}

struct node* malloc_node(int _data)
{
	struct node* node = (struct node *) malloc(sizeof(NODE_SIZE));

	node->i = _data;
	node->next = NULL;

	return node;
}

void add_node(struct list* _list, struct node* _node)
{
	struct node* cur = _list->head_node;
	for (; cur->next != NULL; cur = cur->next)
		;

	cur->next = _node;
	
}

void del_node(struct list* _list, struct node* _node)
{
	struct node * cur = _list->head_node;

	for (; cur->next != _node; cur = cur->next)
		;
	
	cur->next = _node->next;
	_node->next = NULL;
	free(_node);
}




