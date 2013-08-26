#include "common.h"
#include "net.h"
#include "regs.h"

unsigned char heth[6] = {0x00, 0x26, 0x9e, 0x51, 0xd0, 0x69};  //host
unsigned char eeth[6] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66};

unsigned int hip = 192 << 24| ( 168 << 16) | (1 << 8) | 10; //192.168.1.10
unsigned int eip = 192 << 24| ( 168 << 16) | (1 << 8) | 20; //192.168.1.20

unsigned short hport;
unsigned short eport;

unsigned char send_buf[2048];
unsigned char recv_buf[2048];

void do_net(void)
{
	unsigned int len;

	if(!(EINT0PEND & (1 << 7)))
		goto end;
	if((len = eth_recv((void *)recv_buf)) > 14)//判断mac+ip/arp 一共14个字节 大于14表示有数据
		eth_unpack();//板子解包  pc---->板子 板子解包
end:
	EINT0PEND = EINT0PEND;
}


int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("%d", argc);
		printf("\nUsage: go 0x50000000 LoadAdress FileName\n\n");
		return -1;
	}

	hport = htons(69);
	eport = htons(4321);
	
	eth_init();

	irq_disable();
	
	GPNCON |= 2 << 14;
	EINT0CON0 |= 1 << 12;
	EINT0MASK &= ~(1 << 7);//设置网卡中断
	
	irq_request(INT_EINT1, do_net);
	
	irq_enable();

	tftp_down((void *)atoi(argv[1]), argv[2]);

	return 0;
}



