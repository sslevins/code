#include <stdio.h>
#include <stdlib.h>

#include "btree.h"

struct btree* malloc_btree()
{
	struct btree* btree = (struct btree *) malloc(sizeof(struct btree));
	btree->root == NULL;

	return btree;
}

struct node* malloc_node(int _data)
{
	struct node* node = (struct node *) malloc(sizeof(struct node));
	node->data = _data;
	node->parent = NULL;
	node->lchild = NULL;
	node->rchild = NULL;
	node->flag = 0;

	return node;
}

void add_node(struct btree* _btree, int _data)
{
	struct node * node = malloc_node(_data);

	if (_btree->root == NULL)
	{
		_btree->root = node;
		return ;
	}

	struct node* cur = _btree->root;
	struct node* parent = cur;

	while (cur != NULL)
	{
		if (node->data < cur->data)
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

	node->parent = parent;

	if (node->data < parent->data)	
		parent->lchild = node;
	else
		parent->rchild = node;

}

static void __pre_order(struct node* _root)
{
	if (_root == NULL)
	{
		printf("N");
		return ;
	}

	printf("%d", _root->data); 
	__pre_order(_root->lchild);
	__pre_order(_root->rchild);
}

void pre_order(struct btree* _btree)
{
	__pre_order(_btree->root);
	printf("\n");
}

static void __mid_order(struct node* _root)
{
	if (_root == NULL)
		return ;

	__mid_order(_root->lchild);
	printf("%d ", _root->data); 
	__mid_order(_root->rchild);
}

void mid_order(struct btree* _btree)
{
	__mid_order(_btree->root);
	printf("\n");
}


static void __post_order(struct node* _root)
{
	if (_root == NULL)
		return ;

	__post_order(_root->lchild);
	__post_order(_root->rchild);
	printf("%d ", _root->data); 
}

void post_order(struct btree* _btree)
{
	__post_order(_btree->root);
	printf("\n");
}

struct stack* malloc_stack()
{
	struct node * node = (struct node *) malloc(sizeof(struct node));
	node->data = 0;
	node->parent = NULL;
	node->lchild = NULL;
	node->rchild = NULL;

	node->prev = node;
	node->next = node;

	struct stack* stack = (struct stack *) malloc(sizeof(struct stack));
	stack->head_node = node;

	return stack;
}

void push(struct stack * _stack, struct node * _node)
{
	_node->next = _stack->head_node->next;
	_node->prev = _stack->head_node;

	_node->next->prev = _node;
	_node->prev->next = _node;
}

struct node * pop(struct stack * _stack)
{
	if (_stack->head_node->next == _stack->head_node)
	{
		printf("stack is empty\n");
		return NULL;
	}
	
	struct node * cur = _stack->head_node->next;

	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;

	cur->next = cur;
	cur->prev = cur;

	return cur;
}

int is_empty(struct stack* _stack)
{
	if (_stack->head_node->next == _stack->head_node)
		return 1;
	else
		return 0;
}

void pre_order_stack(struct btree* _btree)
{
	struct stack * stack = malloc_stack();

	struct node* cur = _btree->root;

	while (1)
	{
		if (cur == NULL && is_empty(stack))
			break;

		if (cur != NULL)
		{
			printf("%d ", cur->data);
			push(stack, cur);
			cur = cur->lchild;
		}
		else { 	// cur == NULL AND stack != NULL
			cur = pop(stack);
			cur = cur->rchild;
		}
	}
	printf("\n");
}

void mid_order_stack(struct btree* _btree)
{
	struct stack * stack = malloc_stack();
	struct node * cur = _btree->root;

	while (1)
	{
		if (cur == NULL && is_empty(stack))
			break;

		if (cur != NULL)
		{
			push(stack, cur);
			cur = cur->lchild;
		} 
		else
		{
			cur = pop(stack);
			printf("%d ", cur->data);
			cur = cur->rchild;
		}
	}
	printf("\n");

}

void post_order_stack(struct btree* _btree)
{
	struct stack * stack = malloc_stack();
	struct node* cur = _btree->root;

	push(stack, cur);	
	cur->flag = 0;

	while (!is_empty(stack))
	{
		 cur = pop(stack);	
		 if (cur->flag == 1)
		 {
		 	printf("%d ", cur->data);
		 } 
		 else
		 {
		 	push(stack, cur);
			cur->flag = 1;

			if (cur->rchild != NULL)
			{
				push(stack, cur->rchild);
				cur->rchild->flag = 0;
			}
			if (cur->lchild != NULL)
			{
				push(stack, cur->lchild);
				cur->lchild->flag = 0;
			}
		 }
	}
	printf("\n");
}










