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

void level_order(struct btree* _btree)
{
	struct node * cur = _btree->root;
	if (cur == NULL)
	{
		printf("%s: btree is empty\n", __FUNCTION__);
		return ;
	}

	struct queue * queue = malloc_queue();
	in_queue(queue, cur);

	while (!is_empty(queue))
	{
		cur = out_queue(queue);
		if (cur->lchild != NULL)
			in_queue(queue, cur->lchild);
		if (cur->rchild != NULL)
			in_queue(queue, cur->rchild);

		printf("%d ", cur->data);
	}

	printf("\n");

}

struct queue* malloc_queue(void)
{
	struct node * node = (struct node *) malloc(sizeof(struct node));
	node->data = 0;
	node->parent = node;
	node->lchild = node;
	node->rchild = node;
	node->prev = node;
	node->next = node;

	struct queue * queue = (struct queue *) malloc(sizeof(struct queue));
	queue->head_node = node;

	return queue;

}

void in_queue(struct queue* _queue, struct node * _node)
{
	_node->prev = _queue->head_node->prev;
	_node->next = _queue->head_node;

	_node->prev->next = _node;
	_node->next->prev = _node;
}

struct node* out_queue(struct queue* _queue)
{
	struct node* cur = _queue->head_node->next;
	if (cur == _queue->head_node)
	{
		printf("%s: queue is empty\n", __FUNCTION__);
		return ;
	}

	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;

	cur->next = cur;
	cur->prev = cur;

	return cur;
}

int is_empty(struct queue* _queue)
{
	if (_queue->head_node->next == _queue->head_node)
		return 1;
	else
		return 0;
}

void __del_btree(struct node* _node)
{
	if (_node == NULL)
		return ;

	__del_btree(_node->lchild);
	__del_btree(_node->rchild);
	free(_node);
}

void del_btree(struct btree* _btree)
{
	__del_btree(_btree->root);
}

void __del_node_nochild(struct btree* _btree, struct node* _node)
{
	if (_node->parent == NULL)
	{
		_btree->root = NULL;
	}
	else if (_node->parent->lchild == _node)	
	{
		_node->parent->lchild = NULL;
	}
	else if (_node->parent->rchild == _node)
	{
		_node->parent->rchild = NULL;
	}

	_node->parent == NULL;
	free(_node);
}

void __del_node_onechild(struct btree * _btree, struct node* _node)
{
	struct node * child_node = NULL;

	if (_node->lchild != NULL)
		child_node = _node->lchild;
	else
		child_node = _node->rchild;
	
	
	if (_node->parent != NULL && 
			_node->parent->lchild == _node)
	{
		_node->parent->lchild = child_node;
	}
	else if (_node->parent != NULL && 
			_node->parent->rchild == _node)
	{
		_node->parent->rchild = child_node;
	} 
	else
	{
		_btree->root = child_node;
	}
	
	free(_node);
}

void __remove_node_norchild(struct node * _node)
{

	struct node* child_node = _node->lchild;

	if (_node->parent->lchild == _node)
		_node->parent->lchild = child_node;
	else
		_node->parent->rchild = child_node;

	if (child_node != NULL)
		child_node->parent = _node->parent;
	
	_node->parent = NULL;
	_node->lchild = NULL;
}

void __del_node_allchild(struct btree* _btree, struct node * _node)
{
	struct node* the_node = _node->lchild;

	while (the_node->rchild != NULL)
		the_node = the_node->rchild;
	
	__remove_node_norchild(the_node);


	if (_node->parent != NULL)
		the_node->parent = _node->parent;
	the_node->lchild = _node->lchild;
	the_node->rchild = _node->rchild;

	if (_node->parent == NULL)
		_btree->root = the_node;
	else if (_node->parent->lchild == _node)
		_node->parent->lchild = the_node;
	else
		_node->parent->rchild = the_node;
	
	_node->rchild->parent = the_node;
	if (_node->lchild != NULL)
		_node->lchild->parent = the_node;

	_node->parent = NULL;
	_node->lchild = NULL;
	_node->rchild = NULL;
	free(_node);
	
}

void del_node(struct btree* _btree, int _data)
{
	struct node* cur = _btree->root;

	while (cur != NULL)
	{
		if (_data < cur->data)
			cur = cur->lchild;
		else if (_data > cur->data)
			cur = cur->rchild;
		else
			break;
	}

	if (cur == NULL)
		return ;
	
	if (cur->lchild == NULL && cur->rchild == NULL)		
		__del_node_nochild(_btree, cur);
	else if (cur->lchild != NULL && cur->rchild == NULL)
		__del_node_onechild(_btree, cur);
	else if (cur->lchild == NULL && cur->rchild != NULL)
		__del_node_onechild(_btree, cur);
	else
		__del_node_allchild(_btree, cur);

}

void remove_node(struct btree* _btree, int _data)
{
	struct node* cur = _btree->root;

	while (cur != NULL)
	{
		if (_data < cur->data)
			cur = cur->lchild;
		else if (_data > cur->data)
			cur = cur->rchild;
		else
			break;
	}

	if (cur == NULL)
		return ;
	
	if (cur->parent == NULL)
		_btree->root = cur->lchild;
	else if (cur == cur->parent->lchild)
		cur->parent->lchild = cur->lchild;
	else
		cur->parent->rchild = cur->lchild;
	
	if (cur->lchild != NULL)
		cur->lchild->parent = cur->parent;

	cur->parent = NULL;
	cur->lchild = NULL;
	
}





