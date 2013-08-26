#include <stdio.h>

int is_within(char* s1, char* s2)
{
	char* p = s1;
	char* q = s2;
	int num = 0;

	while (*s1 != '\0')
	{
		while (*p != '\0' && 
				*q != '\0' && 
				*p == *q)
		{
			p++;
			q++;
		}

		if (*p == '\0' && *q != '\0')
		{
			break;
		}

		if (*p != '\0' && *q == '\0')
		{
			num++;
		} 

		s1++;
		p = s1;
		q = s2;
	}

	return num;
}

void main()
{
	char* s1 = "abcdefghhehelhellhello";
	char* s2 = "he";

	int ret = is_within(s1, s2);

	printf("%d\n", ret);
}

