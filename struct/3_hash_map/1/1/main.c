#include <stdio.h>

#include "list.h"

static void print_node(struct node* cur)
{
	printf("%d ", cur->data);
}

int main()
{
	int i = 0;

	struct list* hashmap[4];

	for (i = 0; i < 4; i++)
		hashmap[i] = malloc_list();


	for (; i < 200; i++)
		add_item(hashmap, i);
	
	struct node* node = find_item(hashmap, 71);

	printf("%p: %d\n", node, node->data);
	printf("%d %d\n", node->prev->data, node->next->data);

	return 0;
}
