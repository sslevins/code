#include "regs.h"

#define DISABLE_NAND 	NFCONT |= 1 << 1; 
#define ENABLE_NAND	NFCONT &= ~(1 << 1);
#define CHECK_RN	while((NFSTAT & 0x1) == 0) 

void nand_init(void)
{
	GPOCON &= ~0x3;
	GPOCON |= 0x2;
	GPPCON &= ~0xffc0;
	GPPCON |= 0xaa80;

	NFCONF = (0 << 12) | (2 << 8) | (0 << 4) | (1 << 2) | (0 << 0);
	NFCONT = (3 << 6) | (1 << 1) | (1 << 0);

	ENABLE_NAND;
	NFCMMD = 0xff;
	CHECK_RN;
	DISABLE_NAND;
}

void send_addr(unsigned int addr)
{
	unsigned int column_addr = addr & 0x3ff;
	unsigned int raw_addr = (addr >> 11) & 0x1ffff;

	NFADDR = column_addr & 0xff;
	NFADDR = (column_addr >> 8) & 0xf;
	NFADDR = raw_addr & 0xff;
	NFADDR = (raw_addr >> 8) & 0xff;
	NFADDR = (raw_addr >> 16) & 0x1;
}

void send_block_addr(unsigned int addr)
{
	unsigned int raw_addr = (addr >> 11) & 0x1ffff;

	NFADDR = raw_addr & 0xc0;
	NFADDR = (raw_addr >> 8) & 0xff;
	NFADDR = (raw_addr >> 16) & 0x1;
}

void nand_erase(unsigned int dst, unsigned int len)
{
	unsigned int addr = dst;

	ENABLE_NAND;
	for(addr = dst; addr < dst + len; addr += 0x20000){
		NFCMMD = 0x60;
		send_block_addr(addr);	
		NFCMMD = 0xd0;
		CHECK_RN;
	}
	DISABLE_NAND;
}

void nand_read(unsigned int dst, unsigned int src, unsigned int len)
{
	unsigned int addr = dst;
	int i = 0;

	ENABLE_NAND;
	for(addr = src; addr < src + len; addr += 2048){
		NFCMMD = 0x00;
		send_addr(addr);
		NFCMMD = 0x30;
		CHECK_RN;
		for(i = 0; i < 2048; i += 4){
			*(unsigned int *)dst = NFDATA;	
			dst += 4;
		}
	}
	DISABLE_NAND;
}

void nand_write(unsigned int src, unsigned int dst, unsigned int len)
{
	unsigned int addr = dst;
	int i = 0;

	ENABLE_NAND;
	for(addr = dst; addr < dst + len; addr += 2048){
		NFCMMD = 0x80;
		send_addr(addr);
		for(i = 0; i < 2048; i += 4){
			NFDATA = *(unsigned int *)src;
			src += 4;
		}
		NFCMMD = 0x10;
		CHECK_RN;
	}
	DISABLE_NAND;
}
