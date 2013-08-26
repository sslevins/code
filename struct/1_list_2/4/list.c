#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list* malloc_list(void)
{
	struct list_head* node = (struct list_head*) malloc(sizeof(struct list_head));
	node->prev = node;
	node->next = node;

	struct list* list = (struct list *)malloc(sizeof(struct list));
	list->head_node = node;

	return list;
}

struct node* malloc_node(int _data)
{
	struct node* node = (struct node*) malloc(sizeof(struct node));
	node->data = _data;
	node->head.prev = node->head;
	node->head.next = node->head;

	return node;
}

void add_list_head(struct list* _list, struct list_head* _node)
{
	struct list_head* head_node = _list->head_node;

	_node->next = head_node;
	_node->prev = head_node->prev;

	_node->next->prev = _node;
	_node->prev->next = _node;
}

void del_list_head(struct list* _list, struct list_head* _head)
{
	_head->prev->next = _head->next;
	_head->next->prev = _head->prev;

	_head->prev = NULL;
	_head->next = NULL;

	struct node* cur = containerof(_head, struct node, head_node);

	free(cur);
}

void add_node(struct list* _list, struct node* _node)
{
	add_list_head(_list, &_node->xx);
}



