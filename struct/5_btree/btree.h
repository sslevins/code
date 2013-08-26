struct node
{
	int data;

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

struct queue
{
	struct node* head_node;
};

struct btree* malloc_btree(void);
void add_node(struct btree *, int);
void pre_order(struct btree *);
void level_order(struct btree *);

struct queue* malloc_queue(void);
void in_queue(struct queue *, struct node *);
struct node* out_queue(struct queue *);
int is_empty(struct queue *);


