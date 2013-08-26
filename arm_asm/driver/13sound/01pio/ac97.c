#include "regs.h"
#include "common.h"

#define AC97_INT 36

unsigned int music_len;
unsigned int music_addr;
unsigned int music_offset;

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

void do_music_data(void)
{
	if(AC_GLBSTAT & (1 << 21)){
		AC_GLBCTRL |= 1 << 29;
		AC_PCMDATA = *((int *)(music_addr + music_offset));
		music_offset += 4;
		if(music_offset > 44100 * 2 *2 * 20){
			printf("play again...\n");
			music_offset = 0;	
		}
	}
}

void play_music(unsigned int start_addr, unsigned int len)
{
	music_addr = start_addr;
	music_len = len;
	music_offset = 0;

	AC_GLBCTRL |= (1 << 12) | (1 << 21);	
	irq_request(AC97_INT, do_music_data);
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
