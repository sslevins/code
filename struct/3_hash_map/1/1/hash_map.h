#include "list.h"

struct hashmap
{
	struct list* arr;
	unsigned int num;
};

struct hashmap* malloc_hashmap(int);
void add_item(struct list * [], int);
void del_item(void);

struct node* find_item(struct list* hashmap[], int);



