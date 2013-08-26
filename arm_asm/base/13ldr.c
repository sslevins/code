#include <stdio.h>

int main(int argc, char *argv[])
{
	int in = 10;
	int a = 0;
#if 0
	__asm__ __volatile__(
		"data:\n"
		".word 0x1, 0x2, 0x3\n"
		"ldr r0, data\n"
		"mov %0, r0\n"
		"str r0, %1\n"
		:"=&r"(a)			
		:"m"(in)
	);
	printf("a = %d\n", a);
	printf("in = %d\n", in);
#endif
#if 0
	int data1 = 0, data2 = 0, data3 = 0;
	
	__asm__ __volatile__(
		"data:\n"
		".word 0x1, 0x2, 0x3\n"
		"ldr r0, =data\n"
		"ldr %0, [r0]\n"
//		"ldr %1, [r0, #4]\n"
//		"ldr %2, [r0, #8]\n"
		"ldr %1, [r0, #4]!\n"
		"ldr %2, [r0, #4]!\n"
		:"=&r"(data1), "=&r"(data2), "=&r"(data3)
		:
		:"r0"			
	);
	printf("data1 = %d\n", data1);
	printf("data2 = %d\n", data2);
	printf("data3 = %d\n", data3);
#endif
#if 0
	int arr[10];

	__asm__ __volatile__(
		"data:\n"
		".word 0x1, 0x2, 0x3, 0x4\n"
		"ldr r0, =data\n"
		"ldr %0, [r0], #4\n"
		"ldr %1, [r0], #4\n"
		"ldr %2, [r0], #4\n"
		"ldr %3, [r0], #4\n"
		:"=&r"(arr[0]), "=&r"(arr[1]), "=&r"(arr[2]), "=&r"(arr[3])
		:
		:"r0"
	);		
	printf("arr[0] = %d\n", arr[0]);
	printf("arr[1] = %d\n", arr[1]);
	printf("arr[2] = %d\n", arr[2]);
	printf("arr[3] = %d\n", arr[3]);
#endif
	int arr[10];
	int *p = arr;
	int i;

	__asm__ __volatile__(
		"mov r0, #1\n"
		"mov r1, #2\n"
		"mov r2, #3\n"
		"mov r3, #4\n"
		"mov r4, #5\n"
		"str r0, [%0], #4\n"
		"str r1, [%0], #4\n"
		"str r2, [%0], #4\n"
		"str r3, [%0], #4\n"
		"str r4, [%0], #4\n"
		:"+r"(p)
		:
		:"r0", "r1", "r2", "r3", "r4", "r5"
	);		
	for(i = 0; i < 5; i++){
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	
	return 0;
}
