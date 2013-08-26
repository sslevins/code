#include "regs.h"

static int us2cycle(int us);
static void time_init(void);
static void commond(void);

void ddr_init(void)
{
	MEM_SYS_CFG &= ~(1 << 7);
	P1MEMCCMD = 0x4;

	time_init();

	P1MEMCFG = (2 << 15) | (2 << 3) | (2 << 0);
	P1MEMCFG2 = (1 << 11) | (3 << 8) | (1 << 6) | (1 << 0);

	commond();
}

static int us2cycle(int us)
{
	return (us / (1000000000 / 133000000));
}

static void time_init(void)
{
	P1REFRESH = us2cycle(7800); 
	P1CASLAT = 3 << 1;
	P1T_DQSS = 1;
	P1T_MRD	= 2;
	P1T_RAS = us2cycle(45);  
	P1T_RC = us2cycle(68);
	P1T_RCD = us2cycle(23) | ((us2cycle(23) - 3) << 3);
	P1T_RFC = us2cycle(80) | ((us2cycle(80) - 3) << 5); 
	P1T_RP = us2cycle(23) | ((us2cycle(23) - 3) << 3);
	P1T_RRD = us2cycle(15);
	P1T_WR = us2cycle(15);
	P1T_WTR = 1;  
	P1T_XP = us2cycle(9);
	P1T_XSR = us2cycle(120);  
	P1T_ESR = us2cycle(120);  
}

static void commond(void)
{
	P1DIRECTCMD = 2 << 18;
	P1DIRECTCMD = 0 << 18;
	P1DIRECTCMD = 3 << 18;
	P1DIRECTCMD = 3 << 18;
	P1DIRECTCMD = (2 << 18) | (2 << 16);
	P1DIRECTCMD = (2 << 18) | (3 << 4) | (2 << 0);
		
	P1MEMCCMD = 0x0;
	while((P1MEMSTAT & 0x01) == 0); 	
}
