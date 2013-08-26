#include <stdio.h>

#include "stack.h"

enum {
	OPR,
	NUM,
};

void calc(void);

struct stack* num_stack = NULL;
struct stack* opr_stack = NULL;
int flag = OPR;

int get_pri(char opr)
{
	switch (opr)
	{
		case '(' :
			return 0;

		case '+' :
		case '-' :
			return 1;

		case '*' :
		case '/' :
			return 2;

		case 'n':
			return 3;

		default :
			printf("%s: opr error\n", __FUNCTION__);
			return -1;
	}
}

void handler_num(char _p)
{
	int num = _p - '0';

	if (flag == OPR)
	{
		push(num_stack, num);
	}
	else
	{
		int ret = pop(num_stack);
		push(num_stack, ret*10+num);
	}

	flag = NUM;
}

void handler_opr(char _p)
{
	char top_opr;

	while (1)
	{

		if (!is_empty(opr_stack))
			top_opr = get_top(opr_stack);

		if (is_empty(opr_stack))
		{
			push(opr_stack, _p);
			break;
		} 
		else if (get_pri(_p) > get_pri(top_opr))
		{
			push(opr_stack, _p);
			break;
		}
		else
			calc();
	}

	flag = OPR;
}

void handler_brace(char c)
{
	char opr = 0;

	switch (c)
	{
		case '(':
			push(opr_stack, '(');
			break;

		case ')':
			while (1)
			{
				opr = get_top(opr_stack);
				if (opr == '(')
				{
					pop(opr_stack);
					break ;
				}

				calc();
			}

			break;
	}

	flag = OPR;
}

void calc()
{
	int opr = pop(opr_stack);
	int b = pop(num_stack);
	int a = pop(num_stack);

	printf("cur calc: %d %c %d\n", a, (char)opr, b);

	switch (opr)
	{
		case 'n':
			push(num_stack, a);
			push(num_stack, 0-b);
			break;

		case '+' :
			push(num_stack, a+b);
			break;
		case '-' :
			push(num_stack, a-b);
			break;
		case '*' :
			push(num_stack, a*b);
			break;
		case '/' :
			push(num_stack, a/b);
			break;
	}

	flag = NUM;
}

void calc_all()
{
	while(!is_empty(opr_stack))
	{
		calc();
	}
}

void main()
{
	char * str = "3+12*(4*n2-1)";

	num_stack = malloc_stack();
	opr_stack = malloc_stack();

	char * p = str;

	for (; *p != '\0'; p++)
	{
		switch (*p)
		{
			case '0'...'9':
				handler_num(*p);
				break;

			case '+' :
			case '-' :
			case '*' :
			case '/' :
			case 'n' :
				handler_opr(*p);
				break;

			case '(':
			case ')':
				handler_brace(*p);
				break;

			default:
				printf("hello: \n");
		}
	}

	calc_all();

	int ret = pop(num_stack);

	printf("%d \n", ret);
}


