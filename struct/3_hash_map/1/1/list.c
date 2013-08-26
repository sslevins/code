#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list* malloc_list(void)
{
	struct node* head = (struct node *) malloc(sizeof(struct node));
	head->data = 0;
	head->prev = head;
	head->next = head;

	struct list* list = (struct list *) malloc(sizeof(struct list));
	list->head_node = head;

	return list;
}

struct node* malloc_node(int _data)
{
	struct node* node = (struct node *) malloc(sizeof(struct node));
	node->data = _data;
	node->prev = node;
	node->next = node;

	return node;
}

static void insert_node(struct node* _node, 
			struct node* _prev_node, 
			struct node* _next_node)
{
	_node->next = _next_node;
	_node->prev = _prev_node;

	_node->next->prev = _node;
	_node->prev->next = _node;
}

void add_node(struct list* _list, struct node* _node)
{
	insert_node(_node, _list->head_node->prev, _list->head_node);
}

void del_node(struct node* _node)
{
	_node->next->prev = _node->prev;
	_node->prev->next = _node->next;

	_node->prev = _node;
	_node->next = _node;

	free(_node);
}

void list_for_each(struct list* _list, 
		void (*do_it)(struct node *))
{
	struct node* cur = _list->head_node->next;

	for (; cur != _list->head_node; cur = cur->next)
		do_it(cur);
}











