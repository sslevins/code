#include <stdio.h>
#include <stdlib.h>

#include "btree.h"

struct btree* malloc_btree()
{
	struct btree* btree = (struct btree *) malloc(sizeof(struct btree));
	btree->root == NULL;

	return btree;
}

void add_node(struct btree* _btree, struct node* _node)
{
	if (_btree->root == NULL)
	{
		_btree->root = _node;
		return ;
	}

	struct node* cur = _btree->root;
	struct node* parent = cur;

	while (cur != NULL)
	{
		if (_node->data < cur->data)
		{
			parent = cur;
			cur = cur->lchild;
		}
		else
		{
			parent = cur;
			cur = cur->rchild;
		}
	}

	_node->parent = parent;

	if (_node->data < parent->data)	
		parent->lchild = _node;
	else
		parent->rchild = _node;

}

static void __pre_order(struct node* _root)
{
	if (_root == NULL)
	{
		printf("N");
		return ;
	}

	printf("%c", _root->c); 
	printf("(");
	__pre_order(_root->lchild);
	printf(", ");
	__pre_order(_root->rchild);
	printf(")");
}

void pre_order(struct btree* _btree)
{
	__pre_order(_btree->root);
	printf("\n");
}

struct list * malloc_list()
{
	struct node * node = (struct node *) malloc(sizeof(struct node));
	node->data = 0;
	node->parent = NULL;
	node->lchild = NULL;
	node->rchild = NULL;
	node->next = node;
	node->prev = node;

	struct list * list = (struct list *)malloc(sizeof(struct list));
	list->head_node = node;
	
	return list;
}

struct node * malloc_node(char _c, int _data)
{
	struct node * node = (struct node *) malloc(sizeof(struct node));
	node->c = _c;
	node->data = _data;
	node->parent = NULL;
	node->lchild = NULL;
	node->rchild = NULL;
	node->prev = node;
	node->next = node;

	return node;
}

void insert_list(struct list * _list, struct node * _node)
{
	struct node * cur = _list->head_node->next;

	for (; cur != _list->head_node; cur = cur->next)
	{
		if (cur->data >= _node->data)
			break;
	}

	_node->next = cur;
	_node->prev = cur->prev;

	_node->next->prev = _node;
	_node->prev->next = _node;
}

void list_for_each(struct list * _list)
{
	struct node * cur = _list->head_node->next;

	for (; cur != _list->head_node; cur = cur->next)
		printf("%c %d\n", cur->c, cur->data);
}

struct node * remove_node(struct list* _list)
{
	struct node* node = _list->head_node->next;

	node->prev->next = node->next;
	node->next->prev = node->prev;

	node->next = node;
	node->prev = node;

	return node;
}






