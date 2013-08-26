#include <stdio.h>

#include "btree.h"

void main()
{
	struct btree* btree = malloc_btree();

	add_node(btree, 10);
	add_node(btree, 6);
	add_node(btree, 3);

	pre_order(btree);
	//mid_order(btree);
	//post_order(btree);

	//level_order(btree);
	
	//del_node(btree, 6);
	//del_node(btree, 2);
	//del_node(btree, 5);
	//del_node(btree, 7);
	
	remove_node(btree, 3);

	pre_order(btree);

}


