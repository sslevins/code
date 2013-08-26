#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int hash(int _data)
{
	if (_data < 10)
		return 0;
	else if (_data < 50)
		return 1;
	else if (_data < 100)
		return 2;
	else
		return 3;

}

void add_item(struct list* _hashmap[], int _data)
{
	int hash_code = hash(_data);

	struct list* list = _hashmap[hash_code];

	struct node* node = malloc_node(_data);

	add_node(list, node);
}

struct node* find_item(struct list* _hashmap[], int _data)
{
	int hash_code = hash(_data);

	struct list* list = _hashmap[hash_code];

	struct node* cur = list->head_node->next;
	for (; cur != list->head_node; cur = cur->next)
	{
		if (cur->data == _data)
			return cur;
	}
}








