#include <stdio.h>
#include "list.h"

int main(int argc, char* argv[])
{
	struct list * list = NULL;
	struct node * node = NULL;
	struct node * cur = NULL;
	struct node * temp = NULL;

	list = malloc_list();

	node = malloc_node(10);
	temp = node;
	add_node(list, node);

	node = malloc_node(100);
	add_node(list, node);

	node = malloc_node(1000);
	add_node(list, node);

	node = malloc_node(10000);
	add_node(list, node);
	
	for (cur = list->first_node; cur != NULL; cur = cur->next)
		printf("%d ", cur->i);
	
	printf("\n");

	del_node(list, temp);

	for (cur = list->first_node; cur != NULL; cur = cur->next)
		printf("%d ", cur->i);
	
	printf("\n");


	return 0;
}

