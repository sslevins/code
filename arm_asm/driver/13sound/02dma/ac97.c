#include "regs.h"
#include "common.h"

#define AC97_INT 36

unsigned int music_len;
unsigned int music_addr;
unsigned int music_offset;

struct{
	unsigned int sour_addr;
	unsigned int dest_addr;
	unsigned int next;
	unsigned int control0;
	unsigned int control1;
}next_dma;

void delay(int n);
void wm9714_write(unsigned int reg, unsigned int val);

void ac97_init(void)
{
	GPDCON = 0x44444;
	
	AC_GLBCTRL |= 0x01;
	delay(10);
	AC_GLBCTRL &= ~1;
	
	AC_GLBCTRL |= 0x01 << 1;
	delay(10);
	AC_GLBCTRL &= ~(0x01 << 1);

	AC_GLBCTRL |= 0x01 << 2;
	delay(10);
	AC_GLBCTRL |= 0x01 << 3;

	AC_CODEC_CMD |= 0x01 << 23;
	delay(100);

	if((AC_GLBSTAT & 0x7) == 0x03){
		printf("AC97 init ok...\n");
	}else{
		printf("AC97 init not ok...\n");
		printf("The status is %x\n", AC_GLBSTAT & 0x7);
	}
}

wm9714_init(void)
{
	//Table 16 Stereo DAC Volume Control
	wm9714_write(0x0c, 0xf | (0xf << 8));
	wm9714_write(0x5c, 1 << 7);

	//Table 21 Audio Sample Rate Control
	wm9714_write(0x2a, 0x01);
	wm9714_write(0x2c, 0xac44);

	//Table 32 HPL / HPR PGA Input Source
	wm9714_write(0x1c, (2 << 4) | (2 << 6) | (3 << 8) | (3 << 11));	
	//Table 33 HPL / HPR PGA Control
	wm9714_write(0x04, 0x00);
	//Table 37 SPKL / SPKR PGA Control
	wm9714_write(0x02, 0x00);

	//Table 43 Jack Insertion / Auto-Switching (1)
	wm9714_write(0x24, 1 << 4);
	wm9714_write(0x5a, 0 << 6);

	//extended Power Down Register (1) (Additional to AC’97 Rev 2.2)
	wm9714_write(0x26, 0x00);
	wm9714_write(0x3c, 0x00);
	wm9714_write(0x3e, 0x00);
}

void wm9714_write(unsigned int reg, unsigned int val)
{
	AC_CODEC_CMD = (reg << 16) | val;
	delay(10);
}

void dma_init(unsigned int addr, unsigned int len)
{
	next_dma.sour_addr = addr;
	next_dma.dest_addr = (unsigned int)(&AC_PCMDATA);
	next_dma.next = (unsigned int)(&next_dma);
	next_dma.control0 = 1 << 26 | 1 << 25 | 2 << 21 | 2 << 18;
	next_dma.control1 = len >> 2;

	DMACC0LLI = &next_dma;

	SDMA_SEL |= 1 << 22;

	DMACC0SrcAddr = addr;
	DMACC0DestAddr = (unsigned int)(&AC_PCMDATA);
	DMACC0Control0 = 1 << 26 | 1 << 25 | 2 << 21 | 2 << 18;

	DMACC0Control1 = len >> 2;
	DMACC0Configuration = 1 << 11 | 6 << 6 | 1;
}

void play_music(unsigned int start_addr, unsigned int len)
{
	dma_init(start_addr, len);
	AC_GLBCTRL |= 2 << 12;	
	DMACConfiguration = 0x01;
}

void delay(int n)
{
	int i, j;

	for(i = 0; i < n; i++){
		for(j = 0; j < 10000; j++){
			;
		}
	}
}
