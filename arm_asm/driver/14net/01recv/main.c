#include "regs.h"
#include "common.h"

int main(int argc, char *argv[])
{
	char buf[1024];
	
	while(1){
		if(eth_recv(buf) > 0){
			printf(buf + 42);
		}
	}

	return 0;
}
