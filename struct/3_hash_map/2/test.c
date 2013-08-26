#include <stdio.h>

void main()
{
	struct list* list_1 = malloc_list();
	struct list* list_2 = malloc_list();
	struct list* list_3 = malloc_list();
	struct list* list_4 = malloc_list();

	int i = 0;
	for (i = 0; i < 100; i++)
	{
		struct node* node = malloc_node(i);

		if (i < 10)
			add_node(list_1, node);
		else if (i < 20)
			add_node(list_2, node);
		else if (i < 50)
			add_node(list_3, node);
		else
			add_node(list_4, node);
	}

	struct list* arr[4];
	arr[0] = list_1;
	arr[1] = list_2;
	arr[2] = list_3;
	arr[3] = list_4;

}
