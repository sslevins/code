#include "regs.h"
#include "common.h"

void ddr_time(void);
void ddr_cmd(void);

void ddr_init(void)
{
	MEM_SYS_CFG &= ~(1 << 7);
	P1MEMCCMD = 4;

	P1MEMCFG = (2 << 15) | (2 << 3) | (2 << 0);
	P1MEMCFG2 = (1 << 11) | (3 << 8) | (1 << 6) | (1 << 1) | 1;
	
	ddr_time();
	ddr_cmd();
	
	P1MEMCCMD = 0;
	while((P1MEMSTAT & 0x3) != 1);
}

int ns_to_cycle(int ns)
{
	return ns / (1000000000 / 133000000);
}

void ddr_time(void)
{
	P1REFRESH = ns_to_cycle(7800);
	P1CASLAT = 3 << 1;
	P1T_DQSS = 1;
	P1T_MRD = 2;
	P1T_RAS = ns_to_cycle(50);
	P1T_RC = ns_to_cycle(70);
	P1T_RCD = ns_to_cycle(25);
	P1T_RFC = ns_to_cycle(80);
	P1T_RP = ns_to_cycle(25);
	P1T_RRD = ns_to_cycle(20);
	P1T_WR = ns_to_cycle(20);
	P1T_WTR = ns_to_cycle(23) + 2;
	P1T_XP = 2;
	P1T_XSR = ns_to_cycle(120);
	P1T_ESR = ns_to_cycle(120);
}

void ddr_cmd(void)
{
	P1DIRECTCMD = 2 << 18;
	P1DIRECTCMD = 0 << 18;
	P1DIRECTCMD = 3 << 18;
	P1DIRECTCMD = 3 << 18;
	P1DIRECTCMD = (2 << 18) | (2 << 16);
	P1DIRECTCMD = (2 << 18) | (3 << 4) | (2 << 0);
}
