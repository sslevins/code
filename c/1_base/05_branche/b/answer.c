#include <stdio.h>

void main(void)
{
/*
	int i_num = 0;
	int j_num = 0;
	int i_total = 0;
	int j_total = 0;
	int input = 0;

	while (1)
	{
		printf("please input a num: ");
		scanf("%d", &input);

		if (input == 0)
		{
			break;
		}

		if (input % 2 == 0)
		{
			i_num = i_num + 1;
			i_total += input;
		}
		else
		{
			j_num = j_num + 1;
			j_total += input;
		}

	}

	printf("%d, %d\n", 
		i_num, i_num ? i_total/i_num : i_total);

	printf("%d, %d\n", 
		j_num, j_num ? j_total/j_num : j_total);
*/

	int i = 0;
	int total = 0;
	printf("please input a num: ");
	scanf("%d", &i);

	// while (i != 0)
	while (i)
	{
		total = total + i % 10;
		i = i / 10;
	}
	
	printf("%d\n", total);
}





