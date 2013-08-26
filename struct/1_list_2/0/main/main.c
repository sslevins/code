#include <stdio.h>
#include "list.h"

int main(int argc, char* argv[])
{
	struct list * list = NULL;
	list = malloc_list();

	struct node* node_1 = malloc_node(10);
	struct node* node_2 = malloc_node(100);
	struct node* node_3 = malloc_node(1000);
	struct node* node_4 = malloc_node(10000);

	add_node(list, node_1);
	add_node(list, node_2);
	add_node(list, node_3);
	add_node(list, node_4);

	del_node(list, node_3);	

	printf("%d\n", node_3->i);
	//printf("%d\n", node_3->next->i); // node_4->i

	return 0;
}

