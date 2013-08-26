struct node
{
	int data;
	struct node* prev;
	struct node* next;
};

struct list
{
	struct node* head_node;
};

struct list* malloc_list(void);
struct node* malloc_node(int data);
void add_node(struct list *, struct node *);
void del_node(struct node *);
void list_for_each(struct list *, void (*do_it)(struct node *));



