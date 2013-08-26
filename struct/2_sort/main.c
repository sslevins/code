#include <stdio.h>
#include "list.h"

#define LEN 11

void swap(int * pa, int * pb)
{
	int temp = 0;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void bubble_sort(int arr[])
{

	int i, j, temp;
	for (i = 0; i < LEN-1; i++)
	{
		for (j = 0; j < LEN-1-i; j++)
		{
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

void select_sort(int arr[])
{
	int i , j, min_idx;

	for (i = 0; i < LEN; i++)
	{
		min_idx = i;
		for (j = i+1; j < LEN; j++)
		{
			if (arr[min_idx] > arr[j])
				min_idx = j;
		}

		swap(&arr[min_idx], &arr[i]);
	}
}

void insert_sort(int arr[])
{
	int i, j, temp;

	for (i = 1; i < LEN; i++)
	{
	
		for (j = i-1, temp = arr[i]; 
				j >= 0 && arr[j] > temp;
				j--)
				arr[j+1] = arr[j];

		arr[j+1] = temp;
		
	}
}

void quick_sort(int arr[], int arr_len)
{
	if (arr_len == 1)
		return ;
	
	int pivot_idx = arr_len / 2;
	int pivot = arr[pivot_idx];

	int l = 0;
	int r = arr_len-1;

	for (; l < r && arr[l] < pivot; l++)
		;

	for (; l < r && arr[r] >= pivot; r--)
		;

	arr[pivot_idx] = arr[l];

	while (l < r)
	{
		arr[l] = arr[r];
		for (; l < r && arr[l] < pivot; l++)
			;

		arr[r] = arr[l];
		for (; l < r && arr[r] >= pivot; r--)
			;
	}

	arr[l] = pivot;

	if (l > 1)
		quick_sort(arr, l);
	
	if (arr_len-l-1 > 1)
		quick_sort(arr+l+1, arr_len-l-1);

}

void list_bubble_sort(struct list* _list)
{
	struct node* cur = _list->head_node;
	struct node* target = _list->head_node;

	for (target = _list->head_node->prev; 
			target != _list->head_node->next; 
			target = target->prev)
	{
		for (cur = _list->head_node->next; 
				cur != _list->head_node->prev; 
				)
		{
			if (cur->data > cur->next->data)
				swap_node(cur, cur->next);
			else
				cur = cur->next;
		}
	}
}
void list_select_sort(struct list* _list)
{
	struct node* target = _list->head_node;
	struct node* cur = NULL;
	struct node* min_node = NULL;

	for (target = _list->head_node->next;
			target != _list->head_node;
			target = min_node->next)
	{
		min_node = target;

		for (cur = target->next; 
				cur != _list->head_node;
				cur = cur->next)
		{
			if (min_node->data > cur->data)	
				min_node = cur;
		}

		swap_node(target, min_node);

	}

}

void list_insert_sort(struct list* _list)
{
	struct node* cur = _list->head_node;
	struct node* target = _list->head_node;
	struct node* next_node = NULL;

	for (target = _list->head_node->next->next; 
			target != _list->head_node;
			)
	{
		for (cur = target->prev; 
				cur != _list->head_node && 
					cur->data > target->data;
				cur = cur->prev)
			;

		next_node = target->next;
		__del_node(target);
		__insert_node(target, cur, cur->next);
		
		target = next_node;

	}
}

static struct list* init_list(void)
{
	struct list* list = malloc_list();
	struct node* node = NULL;

	node = malloc_node(7);  add_node(list, node);
	node = malloc_node(4);  add_node(list, node);
	node = malloc_node(18); add_node(list, node);
	node = malloc_node(8);  add_node(list, node);
	node = malloc_node(20); add_node(list, node);
	node = malloc_node(3);  add_node(list, node);
	node = malloc_node(6);  add_node(list, node);
	node = malloc_node(2);  add_node(list, node);
	node = malloc_node(5);  add_node(list, node);
	node = malloc_node(11); add_node(list, node);
	node = malloc_node(10); add_node(list, node);

	return list;
}

int main(int argc, char* argv[])
{
	int arr[LEN] = {7, 4, 18, 8, 20, 3, 6, 2, 5, 11, 10};
	
	// bubble_sort(arr);
	// select_sort(arr);
	// insert_sort(arr);
	// quick_sort(arr, LEN);
	int i;
	for (i = 0; i < LEN; i++)	
		;//printf("%d ", arr[i]);
	printf("\n");

	
	struct list* list = init_list();
	
	// list_for_each(list);
	// list_bubble_sort(list);
	// list_select_sort(list);
	// list_insert_sort(list);
	// list_for_each(list);
	

	return 0;
}

