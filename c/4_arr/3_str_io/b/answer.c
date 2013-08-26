#include <stdio.h>
#include <float.h>

int main(void)
{
/*
	// 1
	char fname[40];
	char lname[40];

	printf("Enter your first name: ");
	scanf("%s", fname);
	printf("Ebter your last name: ");
	scanf("%s", lname);
	printf("%s, %s \n", lname, fname);
*/

/*
	// 2
	float height;
	char name[40];

	printf("Enter your height in cm: ");
	scanf("%f", &height);
	printf("Enter your name: ");
	scanf("%s", name);
	printf("%s, you are %.2f M tall \n", name, height / 100.0);
*/

	// 3
	float ot_f = 1.0 / 3.0;
	double ot_d = 1.0 / 3.0;

	printf("float values: ");
	printf("%.4f %.12f %.16f \n", ot_f, ot_f, ot_f);
	printf("double calues: ");
	printf("%.4f %.12f %.16f \n", ot_d, ot_d, ot_d);
	printf("FLT_DIG: %d \n", FLT_DIG);
	printf("DBL_DIG: %d \n", DBL_DIG);
	
	return 0;
}





