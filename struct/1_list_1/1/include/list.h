struct node
{
	int i;
	struct node * next;
};

struct node* malloc_node(int);
void free_node(struct node *);
void add_node(struct node *, struct node *);
void del_node(struct node *);
void free_all_node(struct node *);
