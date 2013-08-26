struct node
{
	int data;
	char c;

	struct node* lchild;
	struct node* rchild;
	struct node* parent;

	struct node* next;
	struct node* prev;
};

struct btree
{
	struct node* root;
};

struct list
{
	struct node* head_node;
};

struct btree* malloc_btree(void);
void add_node(struct btree *, struct node *);
void pre_order(struct btree *);

struct list* malloc_list(void);
struct node* malloc_node(char, int);
void insert_list(struct list*, struct node *);
struct node * remove_node(struct list *);




