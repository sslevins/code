#include <stdio.h>
#include "list.h"

int main(int argc, char* argv[])
{
	struct list * list = NULL;
	list = malloc_list();

	struct node* node_1 = malloc_node(1);
	struct node* node_2 = malloc_node(2);
	struct node* node_3 = malloc_node(3);
	struct node* node_4 = malloc_node(4);

	add_node(list, node_1);
	add_node(list, node_2);
	add_node(list, node_3);
	add_node(list, node_4);

	list_for_each(list);

	//swap_node(node_2, node_3);
	//swap_node(node_1, node_3);
	swap_node(node_1, node_4);

	list_for_each(list);

	return 0;
}

