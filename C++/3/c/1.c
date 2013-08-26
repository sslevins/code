#include <stdio.h>

#define max(A, B) (A)>(B) ? (A) : (B); 

int main()
{
	float i = max(10.1, 20.2);
	// float i = 10.1>20.2 ? 10.1 : 20.2;

	printf("%f\n", i);

}
