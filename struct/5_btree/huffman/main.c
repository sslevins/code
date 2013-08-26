#include <stdio.h>

#include "btree.h"

void main()
{
	char c = 'a';
	int arr[6];
	struct node * arr_node[6];
	int id;
	for (c = 'a'; c <= 'f'; c++)
	{
		id = c - 'a';
		//printf("%c %d\n", c, arr[id]&0x000000ff);
	}

	struct list * list = malloc_list();
	int data = 0;
	struct node * node = NULL;

	arr[0] = 100;
	arr[1] = 90;
	arr[2] = 30;
	arr[3] = 50;
	arr[4] = 10;
	arr[5] = 20;

	for (c = 'a'; c <= 'f'; c++)
	{
		data = arr[c-'a'];
		node = malloc_node(c, data);
		arr_node[c-'a'] = node;
		insert_list(list, node);
	}

	//list_for_each(list);
	struct btree* btree = malloc_btree();

	struct node * cur = list->head_node->next;
	struct node * head_node = list->head_node;
	struct node * node_1 = NULL;
	struct node * node_2 = NULL;
	struct node * node_3 = NULL;

	for (cur = list->head_node->next; 
		head_node->next->next != head_node; 
		cur = cur->next)
	{
		node_1 = remove_node(list);
		node_2 = remove_node(list);
		node_3 = malloc_node(0, node_1->data + node_2->data);
		insert_list(list, node_3);

		node_1->parent = node_3;
		node_3->lchild = node_1;

		node_2->parent = node_3;
		node_3->rchild = node_2; 
	}

	btree->root = head_node->next;

	pre_order(btree);
}




