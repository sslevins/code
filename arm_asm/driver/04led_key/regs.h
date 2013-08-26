#ifndef LZY_REGS_H
#define LZY_REGS_H

/***********************led***************************/
#define GPMCON (*(volatile unsigned int *)0x7F008820) 
#define GPMDAT (*(volatile unsigned int *)0x7F008824)
#define GPMPUD (*(volatile unsigned int *)0x7F008828)
/***********************key***************************/
#define GPNCON (*(volatile unsigned int *)0x7F008830) 
#define GPNDAT (*(volatile unsigned int *)0x7F008834)
#define GPNPUD (*(volatile unsigned int *)0x7F008838)

#endif




