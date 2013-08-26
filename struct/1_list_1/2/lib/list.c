#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define NODE_SIZE sizeof(struct node)
#define LIST_SIZE sizeof(struct list)

struct list* malloc_list(void)
{
	struct list* list = (struct list *)malloc(LIST_SIZE);
	list->first_node = NULL;

	return list;
}

struct node* malloc_node(int _data)
{
	struct node* node = (struct node *)malloc(NODE_SIZE);
	node->i = _data;
	node->next = NULL;

	return node;
}

void add_node(struct list* _list, struct node* _node)
{
	struct node * cur = _list->first_node;

	if (cur == NULL) {

		_list->first_node = _node;

	} else {

		while (cur->next != NULL)
			cur = cur->next;
	
		cur->next = _node;
	}
}

void del_node(struct list* _list, struct node* _node)
{
	struct node * cur = _list->first_node;
	
	if (_node == _list->first_node)
	{
		_list->first_node = _node->next;
		goto del;
	}

	for ( ; cur != NULL && cur->next != _node; cur = cur->next)
		;

	if (cur == NULL)
		return ;
	
	cur->next = _node->next;

del:
	_node->next = NULL;
	free(_node);
}

void free_all_node(struct node* _node)
{
	if (_node == NULL)
		return ;

	free_all_node(_node->next);

	free(_node);
	//printf("%d ", _node->i);
}











