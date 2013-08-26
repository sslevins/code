#include <stdio.h>

int power(int a, int b);

int main(void)
{
/*
	// 1
	char *p = "01001001";

	while (*p != '\0') //最后一次进循环时，*p是最后一个1
		p++;	// 最后一次进循环以后，*p指向了'\0'

	p--;	// 最后一个1
	
	int i = 0;
	int ret = 0;
	for (i = 0; i < 8; i++, p--)
	{
		if (*p == '0')
			ret += 0 << i;
		else
			ret += 1 << i;
	}

	printf("%d\n", ret);
*/

	int a = 0x010010001;
	int i = 0;
	int j = 0;
	int num = 0;

	for (i = 0; i < 32; i++)
	{
		j = (a >> i) & 0x01;

		if (j == 1)
			num ++;
		else
			;
	}
	printf("%d\n", num);

	return 0;
}


