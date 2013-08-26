#include "regs.h"
#include "common.h"

#define ENABLE_NAND	NFCONT &= ~(1 << 1)
#define DISABLE_NAND	NFCONT |= 1 << 1
#define WAIT_NAND	while(!(NFSTAT & 1))

void nand_init(void)
{
	GPOCON &= ~0xf;
	GPOCON |= 0xa;

	GPPCON &= ~0xffc0;
	GPPCON |= 0xaa80;

	NFCONF = (0 << 12) | (2 << 8) | (0 << 4) | (1 << 2);
	NFCONT = (1 << 6) | (1 << 7) | (1 << 1) | (1 << 0);

	ENABLE_NAND;
	NFCMMD = 0xff;
	WAIT_NAND;
	DISABLE_NAND;
}

void send_addr(unsigned int addr)
{
	unsigned int column_addr = addr & 0x7ff;
	unsigned int raw_addr = (addr >> 11) & 0x1ffff; 
	
	NFADDR = column_addr & 0xff;
	NFADDR = (column_addr >> 8) & 0x7;
	NFADDR = raw_addr & 0xff;
	NFADDR = (raw_addr >> 8) & 0xff;
	NFADDR = (raw_addr >> 16) & 0x1;
}

void send_page_addr(unsigned int addr)
{
        unsigned int raw_addr = (addr >> 11) & 0x1ffff;

        NFADDR = raw_addr & 0xff;
        NFADDR = (raw_addr >> 8) & 0xff;
        NFADDR = (raw_addr >> 16) & 0x1;
}

void nand_erase(unsigned int start, unsigned int len)
{
	int addr = start;

	ENABLE_NAND;
	for(addr = start; addr < start + len; addr += 64*2048){
		NFCMMD = 0x60;
		send_page_addr(addr);
		NFCMMD = 0xD0;
		WAIT_NAND;	
	}
	DISABLE_NAND;
}

void nand_read(unsigned int ddr, unsigned int nand, unsigned int len)
{
	unsigned int addr = nand;
	int i;
	
	ENABLE_NAND;
	for(addr = nand; addr < nand + len; addr += 2048){
		NFCMMD = 0x00;
		send_addr(addr);
		NFCMMD = 0x30;
		WAIT_NAND;
		for(i = 0; i < 2048; i += 4, ddr += 4){
			*((volatile unsigned int *)ddr) = NFDATA;
		}
	}

	DISABLE_NAND;
}

void nand_write(unsigned int ddr, unsigned int nand, unsigned int len)
{
	unsigned int addr = nand;
	int i;

	ENABLE_NAND;
	for(addr = nand; addr < nand + len; addr += 2048){
		NFCMMD = 0x80;
		send_addr(addr);
		for(i = 0; i < 2048; i += 4, ddr += 4){
			NFDATA = *((volatile unsigned int *)ddr);
		}
		NFCMMD = 0x10;
		WAIT_NAND;
	}
	DISABLE_NAND;
}
