#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define NODE_SIZE sizeof(struct node)
#define LIST_SIZE sizeof(struct list)

struct list* malloc_list(void)
{
	struct node * node = (struct node *) malloc(NODE_SIZE);
	node->data = 0;
	node->prev = node;
	node->next = node;

	struct list* list = (struct list *)malloc(LIST_SIZE);
	list->head_node = node;

	return list;
}

struct node* malloc_node(int _data)
{
	struct node* node = (struct node *) malloc(sizeof(NODE_SIZE));

	node->data = _data;
	node->prev = node;
	node->next = node;

	return node;
}

static void __insert_node(struct node* _node, struct node* _prev_node, struct node* _next_node)
{
	_node->next = _next_node;
	_node->prev = _prev_node;

	_next_node->prev = _node;
	_prev_node->next = _node;
}

void add_node(struct list* _list, struct node* _node)
{
	struct node * head_node = _list->head_node;

	_node->next = head_node;
	_node->prev = head_node->prev;

	_node->next->prev = _node;
	_node->prev->next = _node;
}

static struct node* __del_node(struct node* _node)
{
	_node->prev->next = _node->next;
	_node->next->prev = _node->prev;

	_node->prev = NULL;
	_node->next = NULL;

	return _node;
}

void del_node(struct node* _node)
{
	__del_node(_node);

	free(_node);
}

void del_list(struct list * _list)
{
	struct node* cur = _list->head_node->next;
	for (; cur != _list->head_node; cur = cur->next)
		del_node(cur);
	
	free(_list->head_node);
	free(_list);
}

struct node* find_node(struct list* _list, int _data)
{
	struct node* cur = _list->head_node->next;
	for (; cur != _list->head_node; cur = cur->next)
	{
		if (cur->data == _data)
			return cur;
	}

	return NULL;
	
}

void list_for_each(struct list* _list)
{
	struct node* head_node = _list->head_node;
	struct node* cur = NULL;

	for (cur = head_node->next; 
			cur != _list->head_node; 
			cur = cur->next)
		printf("%d ", cur->data);
	
	printf("\n");
}

void reverse(struct list* _list)
{
	struct node* cur = _list->head_node;
	struct node* temp = NULL;

	do
	{
		temp = cur->next;
		cur->next = cur->prev;
		cur->prev = temp;

		cur = cur->prev;
	} while (cur!= _list->head_node);
}

void swap_node(struct node* _node_1, struct node* _node_2)
{
/*
	struct node* temp = (struct node *)malloc(sizeof(struct node));

	__insert_node(temp, _node_1, _node_1->next);

	__del_node(_node_1);
	__insert_node(_node_1, _node_2, _node_2->next);

	__del_node(_node_2);
	__insert_node(_node_2, temp->prev, temp);

	del_node(temp);
*/

	if (_node_1->next == _node_2)
	{
		_node_1->next = _node_2->next;
		_node_2->next->prev = _node_1;

		_node_2->prev = _node_1->prev;
		_node_1->prev->next = _node_2;

		_node_2->next = _node_1;
		_node_1->prev = _node_2;
	
		return ;
	}

	if (_node_1->next == _node_2->prev)
	{
		struct node* mid = _node_1->next;

		_node_1->next = _node_2->next;
		_node_2->next->prev = _node_1;

		_node_2->prev = _node_1->prev;
		_node_1->prev->next = _node_2;

		_node_2->next = mid;
		_node_1->prev = mid;
		mid->next = _node_1;
		mid->prev = _node_2;

		return ;
	}

	if (_node_1->next != _node_2->prev)
	{
		struct node* node_a = _node_1->next;
		struct node* node_b = _node_2->prev;

		_node_1->next = _node_2->next;
		_node_2->next->prev = _node_1;

		_node_2->prev = _node_1->prev;
		_node_1->prev->next = _node_2;

		_node_2->next = node_a;
		node_a->prev = _node_2;

		_node_1->prev = node_b;
		node_b->next = _node_1;

		return ;
	}
	
}







