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
/***********************clock*************************/
#define APLL_LOCK      	(*(volatile unsigned int *)0x7E00F000)  
#define MPLL_LOCK      	(*(volatile unsigned int *)0x7E00F004) 
#define EPLL_LOCK      	(*(volatile unsigned int *)0x7E00F008) 
#define APLL_CON      	(*(volatile unsigned int *)0x7E00F00C) 
#define MPLL_CON       	(*(volatile unsigned int *)0x7E00F010) 
#define EPLL_CON0      	(*(volatile unsigned int *)0x7E00F014) 
#define EPLL_CON1      	(*(volatile unsigned int *)0x7E00F018) 
#define CLK_SRC       	(*(volatile unsigned int *)0x7E00F01C) 
#define CLK_DIV0       	(*(volatile unsigned int *)0x7E00F020) 
#define CLK_DIV1       	(*(volatile unsigned int *)0x7E00F024) 
#define CLK_DIV2       	(*(volatile unsigned int *)0x7E00F028) 
#define CLK_OUT       	(*(volatile unsigned int *)0x7E00F02C) 
#define HCLK_GATE      	(*(volatile unsigned int *)0x7E00F030) 
#define PCLK_GATE      	(*(volatile unsigned int *)0x7E00F034) 
#define SCLK_GATE      	(*(volatile unsigned int *)0x7E00F038) 
#define MEM0_CLK_GATE 	(*(volatile unsigned int *)0x7E00F03C) 
#define AHB_CON0       	(*(volatile unsigned int *)0x7E00F100) 
#define AHB_CON1       	(*(volatile unsigned int *)0x7E00F104) 
#define AHB_CON2       	(*(volatile unsigned int *)0x7E00F108) 
#define CLK_SRC2      	(*(volatile unsigned int *)0x7E00F10C) 
#define SDMA_SEL      	(*(volatile unsigned int *)0x7E00F110) 
#define SYS_ID         	(*(volatile unsigned int *)0x7E00F118) 
#define SYS_OTHERS    	(*(volatile unsigned int *)0x7E00F11C) 
#define MEM_SYS_CFG    	(*(volatile unsigned int *)0x7E00F120) 
#define QOS_OVERRIDE1  	(*(volatile unsigned int *)0x7E00F128) 
#define MEM_CFG_STAT  	(*(volatile unsigned int *)0x7E00F12C) 
#define PWR_CFG       	(*(volatile unsigned int *)0x7E00F804) 
#define EINT_MASK     	(*(volatile unsigned int *)0x7E00F808) 
#define NORMAL_CFG    	(*(volatile unsigned int *)0x7E00F810) 
#define STOP_CFG      	(*(volatile unsigned int *)0x7E00F814) 
#define SLEEP_CFG     	(*(volatile unsigned int *)0x7E00F818) 
#define STOP_MEM_CFG 	(*(volatile unsigned int *)0x7E00F81C) 
#define OSC_FREQ      	(*(volatile unsigned int *)0x7E00F820) 
#define OSC_STABLE    	(*(volatile unsigned int *)0x7E00F824) 
#define PWR_STABLE   	(*(volatile unsigned int *)0x7E00F828) 
#define MTC_STABLE    	(*(volatile unsigned int *)0x7E00F830) 
#define MISC_CON      	(*(volatile unsigned int *)0x7E00F838) 
#define OTHERS        	(*(volatile unsigned int *)0x7E00F900) 
#define RST_STAT      	(*(volatile unsigned int *)0x7E00F904) 
#define WAKEUP_STAT   	(*(volatile unsigned int *)0x7E00F908) 
#define BLK_PWR_STAT 	(*(volatile unsigned int *)0x7E00F90C) 
#define INFORM0      	(*(volatile unsigned int *)0x7E00FA00) 
#define INFORM1      	(*(volatile unsigned int *)0x7E00FA04) 
#define INFORM2      	(*(volatile unsigned int *)0x7E00FA08) 
#define INFORM3      	(*(volatile unsigned int *)0x7E00FA0C)


#endif




