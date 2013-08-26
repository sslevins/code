#include <stdio.h>
#include "list.h"

int main(int argc, char* argv[])
{
	struct node * node = NULL;
	struct node * cur = NULL;

	node = malloc_node(10);
	
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		cur = malloc_node(10*i);
		add_node(node, cur);
	}

	cur = node;

	for (cur = node; cur != NULL; cur = cur->next)
		printf("%d ", cur->i);
	printf("\n");
	

	free_all_node(node);

	return 0;
}

