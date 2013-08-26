#include "regs.h" 
#include "setup.h"

#define SHELL "[zyli@Uplooking]# "

void boot_kernel(void);

int main(void)
{
	char buf[1024];	
	
	uart_init();
	led_on(2);

	while(1){
		uprintf(SHELL);
		ugets(buf);
		uprintf("\r");
	}	

}

