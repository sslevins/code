#include <stdio.h>

#include "btree.h"

void main()
{
	struct btree* btree = malloc_btree();

	add_node(btree, 9);
	add_node(btree, 5);
	add_node(btree, 2);
	add_node(btree, 7);
	add_node(btree, 10);
	add_node(btree, 8);
	add_node(btree, 3);
	add_node(btree, 6);

	pre_order(btree);
	pre_order_stack(btree);

	printf("-----------\n");

	mid_order(btree);
	mid_order_stack(btree);

	printf("-----------\n");
	post_order(btree);
	post_order_stack(btree);

}




