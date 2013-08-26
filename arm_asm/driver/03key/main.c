#include "regs.h"
#include "common.h"

void delay(int n);

int main(int argc, char *argv[])
{	
	key_init();	
	while(1){
		switch(GPNDAT & 0xf){
			case 0xe:
				printf("key 0 is down...\n");
				break;
			case 0xd:
				printf("key 1 is down...\n");
				break;
			case 0xb:
				printf("key 2 is down...\n");
				break;
			case 0x7:
				printf("key 3 is down...\n");
				break;
			default:
				printf("no key is down...\n");
				break;
		}
	}

	return 0;
}

void delay(int n)
{
	int i, j;

	for(i = 0; i < n; i++){
		for(j = 0; j < 1000; j++){
			;
		}	
	}
}
