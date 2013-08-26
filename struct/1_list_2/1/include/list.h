struct list
{
	struct node * head_node;
};

struct node
{
	int i;
	struct node * prev;
	struct node * next;
};

struct list* malloc_list(void);
struct node* malloc_node(int);
void add_node(struct list *, struct node *);
void del_node(struct list *, struct node *);
void list_for_each(struct list *);






