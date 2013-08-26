#include <stdio.h>
#include <string.h>

int do_it(char* s1, char* s2)
{
	int num = 0;
	char* p = s2;

	while (*s1 == *s2)
	{
		s1++;
		s2++;

		if (*s2 == '\0')
		{
			num++;
			s2 = p;
		}
	}

	return num;
}

void main()
{
	char* s1 = "aaaaaaaaaa";
	char* s2 = "aa";

	int ret = do_it(s1, s2);

	printf("%d\n", ret);
}
