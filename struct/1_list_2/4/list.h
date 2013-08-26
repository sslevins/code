struct list
{
	struct list_head * head_node;
};

struct list_head
{
	struct list_head * prev;
	struct list_head * next;
};

struct node
{
	int data;
	struct list_head head;
};

struct list* malloc_list(void);
struct list_head* malloc_list_head();
void add_list_head(struct list *, struct list_head *);
void del_list_head(struct list *, struct list_head *);
void add_node(struct list *, struct node *);


#define offsetof(type, member) \
	(unsigned int)&(((type *)0x0)->member)
   
#define containerof(ptr, type, member) \
	(type *)((char *)ptr - offsetof(type, member))

