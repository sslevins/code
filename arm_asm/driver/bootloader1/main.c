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
		if(strcmp(buf, "bootm") == 0){
			boot_kernel();	
		}
		uprintf("\r");
	}	

}

void boot_kernel(void)
{
	nand_read(0x50008000, 0x40000, 0x300000);
	uprintf("\rkernel is booting...\n");
	
	void (*kernel)(int zero, int type, char *list) = (void *)0x50008000;

	char *cmd_line = "mem=128M root=/dev/nfs nfsroot=192.168.1.10:/nfsroot ip=192.168.1.20 console=ttySAC0,115200";

	int *list = (void *)0x50000100;
	
	*list = 2;//长度 单位是word 本身占一个 word  flags占一个word
	*(list + 1) = ATAG_CORE;

	list += *list;
	*list = ((strlen(cmd_line) + 1 + 3) >> 2) + 2;//加上尾0 和字节对齐  长度和标志占2个word
	*(list + 1) = ATAG_CMDLINE;
	strcpy((void *)(list + 2), cmd_line);

	list += *list;	
	*list = 0;
	*(list + 1) = ATAG_NONE;	

	kernel(0, 1626, (void *)list);
//setup.h包含list的实现
}
