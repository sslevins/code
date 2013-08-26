#include "common.h"
#include "net.h"

static char *load_addr;
static char load_stat;
static short last_no;
static int last_len;
static int sign;
static int line;
static char *block = (char *)0x56000000;//位图 相当于存储是否收到所有的包 从0x560000开始记录 1：收到这个包  0：没有收到这个包
//存储数据
void store_data(char *data, unsigned int len, unsigned short no)
{
	int i;

	if(block[no] == 0)//是0则这个包还没有收到 相当于包的编号 在tftp格式里面有一个就是编号
	{
		memcpy(load_addr + (no - 1) * 512, data, len);//每一个包是521字节 将数据保存到指定地址上去  load_addr+(no - 1)*512 表示第no个包的地址
		block[no] = 1;//收到包则将该位置1
		sign++;//记录收到包的个数 当为6的时候 打印“#”
		if(sign > 5)
		{
			printf("#");
			sign = 0;
			line++;//记录一行的包的个数
			if(line > 64)//到64个则换行
			{
				printf("\n\t");
				line = 0;
			}
		}
	}

	if(len < 512)//当长度小于512字节时 表示结束
	{
		last_no = no;
		last_len = len;
	}

	if(last_no != 0)//当结束后 将block数组的所有的值置0
	{
		for(i = last_no; i > 0; i--)
		{
			if(block[i] == 0)
				return;
		}
		load_stat = 0;//把状态置1
	}

#ifdef DEBUG	
	printf("Save block# %d, len = %d Done.\n", no, len);
#endif
}

//板子 ------->pc 回ACK
void send_ack(unsigned short port, unsigned short no)
{
	unsigned short *tftp = (unsigned short *)(send_buf + sizeof(eth_h) + sizeof(ip_h) + sizeof(udp_h));//

#ifdef DEBUG
	printf("send ack... port = %d, block# = %d\n", htons(port), no);
#endif
	tftp[0] = htons(TFTP_ACK);//发ACK
	tftp[1] = htons(no);//发第几块编号
	udp_pack(4, port);//封udp包

#ifdef DEBUG
	printf("send ack... Done.\n");
#endif
}
//解tftp包 pkt:指向tftp包 的首地址
void tftp_unpack(char *pkt, unsigned int len, unsigned short port)
{
	unsigned short no;

	switch(htons(((unsigned short *)pkt)[0]))
	{
		case TFTP_DATA:
			no = htons(((unsigned short *)pkt)[1]);//第几个包 编号

			if((no < 1) || (no > MAX_BLOCK) || (len < 4) || len > 516)//当编号为0 或者大于
			{
				printf("Error: block#: %d, len: %d\n", no, len);
				return;
			}
			
			store_data(pkt + 4, len - 4, no);//保存数据

			send_ack(port, no);//回ack
			break;

		case TFTP_OACK:
			send_ack(port, 0);//如果是ack 就回pc一个请求包
			break;

		case TFTP_ERROR://如果是错误 则打印
			printf("Error: %s\n", pkt + 4);
			break;

		default:
			printf("Unkown Opcode.\n");
	}
}

void tftp_down(char *addr, char *filename)
{
	unsigned int len;
	char *tftp;

	load_addr = addr;
	load_stat = 1;//下载结束后置0
	last_no = 0;
	sign = 17; //17 > 16
	line = 0;
	memset(block, 0, MAX_BLOCK + 1);//设置数组所有的值为0

/****************** tftp_pack()  tftp封包 ******************************/

	tftp = (char *)(send_buf + sizeof(eth_h) + sizeof(ip_h) + sizeof(udp_h));
	len = 0;

	*(unsigned short *)tftp = htons(TFTP_RRQ);
	len += 2;//TFTP_RRQ占两个字节

	strcpy(tftp + len, filename);
	len += strlen(filename) + 1;

	strcpy(tftp + len, "octet");//模式 mail octet:二进制模式  ascii 
	len += 5 + 1; //strlen("octet") + 1

	strcpy(tftp + len, "timeout");//服务器给板子 发数据 板子5s不回复就超时
	len += 7 + 1; //strlen("timeout") + 1

	*(tftp + len) = '5'; 	//5 Seconds
	*(tftp + len + 1) = 0;
	len += 2;

/************************************************/
	
	printf("Load address: 0x%08x\n", load_addr);
	printf("Loading:\n\t");

	udp_pack(len, hport);	//Read Request 板子------->pc 发送读请求

	while(load_stat != 0)      //等待所有的包发送完成 当pc有数据时发出 dm9000会产生中断
		delay(100);

	printf("\nDone.\n");
	printf("Bytes transferred = %d\n", (last_no - 1) * 512 + last_len);//last_no:打印总的长度
}


