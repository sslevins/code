#include "regs.h"
#include "common.h"

void key_init(void)
{
	GPNCON &= ~0xff;
}
