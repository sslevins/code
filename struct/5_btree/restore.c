#include <stdio.h>
#include <stdlib.h>

struct node 
{
	char c;

	struct node * lchild;
	struct node * rchild;
};

void pre_order(struct node* _node)
{
	if (_node == NULL)
		return;

	printf("%c ", _node->c);
	pre_order(_node->lchild);
	pre_order(_node->rchild);
}

struct node * restore_pre_mid(char * _pre_str, char * _mid_str, int str_len)
{
	if (str_len < 1)
		return NULL;

	struct node* node = (struct node *)malloc(sizeof(struct node));
	node->c = *_pre_str;

	char c = *_pre_str;

	char * p = _mid_str;
	int i = 0;
	for (p = _mid_str; *p != c; p++, i++)
		;
	
	node->lchild = restore_pre_mid(_pre_str+1, _mid_str, i);
	node->rchild = restore_pre_mid(_pre_str+i+1, _mid_str+i+1, str_len-i-1);

	return node;
}

void main()
{
	char * pre_str = "ABDECFG";
	char * mid_str = "DBEAFCG";

	struct node * root = restore_pre_mid(pre_str, mid_str, 7);

	pre_order(root);
	printf("\n");
}



