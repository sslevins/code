#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define NODE_SIZE sizeof(struct node)
#define LIST_SIZE sizeof(struct list)

struct list* malloc_list(void)
{
	struct node * node = (struct node *) malloc(NODE_SIZE);
	node->i = 0;
	node->prev = node;
	node->next = node;

	struct list* list = (struct list *)malloc(LIST_SIZE);
	list->head_node = node;

	return list;
}

struct node* malloc_node(int _data)
{
	struct node* node = (struct node *) malloc(sizeof(NODE_SIZE));

	node->i = _data;
	node->prev = node;
	node->next = node;

	return node;
}

void add_node(struct list* _list, struct node* _node)
{
	struct node * head_node = _list->head_node;

	_node->next = head_node;
	_node->prev = head_node->prev;

	_node->next->prev = _node;
	_node->prev->next = _node;
}

void del_node(struct list* _list, struct node* _node)
{
	_node->prev->next = _node->next;
	_node->next->prev = _node->prev;

	_node->prev = NULL;
	_node->next = NULL;

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
		printf("%d ", cur->i);
	
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






