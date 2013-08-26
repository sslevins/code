#include "stack.h"

struct stack * malloc_stack(void)
{
	struct node * node = (struct node *) malloc(sizeof(struct node));
	node->data = 0;
	node->prev = node;
	node->next = node;

	struct stack * stack = (struct stack *) malloc(sizeof(struct stack));
	stack->head_node = node;

	return stack;
}

struct node * malloc_node(int _data)
{
	struct node * node = (struct node *) malloc(sizeof(struct node));
	node->data = _data;
	node->prev = node;
	node->next = node;

	return node;
}

void push(struct stack * _stack, int _data)
{
	struct node * node = (struct node *) malloc(sizeof(struct node));
	node->data = _data;

	node->prev = _stack->head_node;
	node->next = _stack->head_node->next;

	node->prev->next = node;
	node->next->prev = node;
}

int pop(struct stack * _stack)
{
	if (_stack->head_node->next == _stack->head_node)
		return 0;

	struct node * node = _stack->head_node->next;
	
	node->prev->next = node->next;
	node->next->prev = node->prev;

	node->prev = node;
	node->next = node;

	int ret = node->data;
	free(node);

	return ret;
}

int get_top(struct stack * _stack)
{
	if (is_empty(_stack))
	{
		printf("%s: stack is empty\n", __FUNCTION__);
		exit(1);
	}

	return _stack->head_node->next->data;

}

int is_empty(struct stack * _stack)
{
	if (_stack->head_node->next == _stack->head_node)
		return 1;
	else
		return 0;
}

void stack_for_each(struct stack * _stack, void (*do_it)(struct node *))
{
	struct node * cur = _stack->head_node->next;

	for (; cur != _stack->head_node; cur = cur->next)
		do_it(cur);
}

