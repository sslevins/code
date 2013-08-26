#include "common.h"
#include "regs.h"

void wdt_init(int ms)
{
	WTCON = (65 << 8) | (1 << 3) | (1 << 2) | 0;
	WTCNT = 31 * ms;
	WTDAT = 31 * ms;
}
