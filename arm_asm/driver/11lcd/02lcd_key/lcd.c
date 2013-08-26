#include "regs.h"
#include "common.h"

//#define BPP565 1

void gpio_init(void);
void common_init(void);
void window0_init(void);

void lcd_init(void)
{
	gpio_init();
	common_init();
	window0_init();
}

void gpio_init(void)
{
	GPICON = 0xaaaaaaaa;
	GPJCON = 0xaaaaaa;
	GPFCON &= ~(3 << 28);
	GPFCON |= 1 << 28;
	GPECON &= ~0xf;
	GPECON |= 1;
	
	GPFDAT |= 0x1 << 14;
	GPEDAT |= 0x1;
}

void common_init(void)
{
	MIFPCON &= ~(1 << 3);
	SPCON &= ~0x3;
	SPCON |= 0x1;

	VIDCON0 = (14 << 6) | (1 << 4) | (1 << 1) | 1;
	VIDCON1 = (1 << 6) | (1 << 5);
	VIDCON2 = 0;
	VIDTCON0 = (1 << 16) | (1 << 8) | 9;
	VIDTCON1 = (1 << 16) | (1 << 8) | 40;
	VIDTCON2 = (271 << 11) | 479;
}

void window0_init(void)
{
#ifdef BPP565
	WINCON0 = (1 << 16) | (5 << 2) | 1;
	VIDOSD0C = 272 * 480 / 2;
#else
	WINCON0 = (0xb << 2) | 1;
	VIDOSD0C = 272 * 480;
#endif 
	VIDOSD0A = 0;
	VIDOSD0B = (479 << 11) | 271;
	VIDW00ADD0B0 = FRAME_BUF;
}
