#include "queue.h"

struct queue* malloc_queue(void)
{
	struct node * node = (struct node *)malloc(sizeof(struct node));
	node->data = 0;
	node->prev = node;
	node->next = node;

	struct queue * queue = (struct queue *) malloc(sizeof(struct queue));
	queue->head_node = node;

	return queue;
}

struct node * malloc_node(int _data) 
{
	struct node* node = (struct node *) malloc(sizeof(struct node));
	node->data = _data;
	node->prev = node;
	node->next = node;

	return node;
}

void in_queue(struct queue* _queue, struct node* _node)
{
	_node->next = _queue->head_node;
	_node->prev = _queue->head_node->prev;
	
	_node->next->prev = _node;
	_node->prev->next = _node;
}

struct node* out_queue(struct queue* _queue)
{
	if (_queue->head_node->next == _queue->head_node)
		return NULL;

	struct node* node = _queue->head_node->next;

	node->prev->next = node->next;
	node->next->prev = node->prev;

	node->prev = node;
	node->next = node;

	return node;
}

void queue_for_each(struct queue* _queue, 
	void (*do_it)(struct node *))
{
	struct node* cur = _queue->head_node->next;

	for (; cur != _queue->head_node; 
			cur = cur->next)
		do_it(cur);
}



