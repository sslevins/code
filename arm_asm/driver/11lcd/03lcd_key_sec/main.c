#include "regs.h"
#include "common.h"

void irq_handle(void);
void change_pic(int n);

int main(int argc, char *argv[])
{
	lcd_init();

	GPNCON &= ~0xff;
	GPNCON |= 0xaa;

	EINT0CON0 &= ~0xff;
	EINT0CON0 |= 0x22;

	EINT0MASK &= ~0xf;

	irq_request(0, irq_handle);

	return 0;
}

void irq_handle(void)
{
	switch(EINT0PEND & 0xf){
		case 1:
		case 2:
			change_pic(1);
			break;
		case 4:
		case 8:
			change_pic(0);
			break;
		default:
			printf("no key\n");
			break;
	}

	EINT0PEND = EINT0PEND;
}

void change_pic(int n)
{
	static int index = 1;

	if(n == 1){
		index++;
		if(index == 5){
			index = 0;
		}
	}else{
		index--;
		if(index < 0){
			index = 4;
		}
	}
 	VIDW00ADD0B0 = FRAME_BUF + index * 480 * 272 * 4;
}
