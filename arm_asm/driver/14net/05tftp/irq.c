#include "common.h"
#include "regs.h"

void do_irq(void)
{
	void (*handle)(void) = NULL;

	if(VIC0ADDRESS){
		handle = (void *)VIC0ADDRESS;
	}else if(VIC1ADDRESS){
		handle = (void *)VIC1ADDRESS;
	}

	VIC0ADDRESS = 0;
	VIC1ADDRESS = 0;

	if(handle){
		handle();
		handle = NULL;
	}
	
	VIC0SOFTINTCLEAR = VIC0IRQSTATUS;
	VIC1SOFTINTCLEAR = VIC1IRQSTATUS;

}

int irq_request(int irq_no, void (*handle)(void))
{
	if(irq_no >= 0 && irq_no <=31){
		VIC0INTSELECT &= 1 << irq_no; 
		VIC0INTENABLE |= 1 << irq_no;
		VIC0VECTADDR[irq_no] = (int)handle;
	}else if(irq_no >= 32 && irq_no <= 63){
		irq_no -= 32;
		VIC1INTSELECT &= 1 << irq_no; 
		VIC1INTENABLE |= 1 << irq_no;
		VIC1VECTADDR[irq_no] = (int)handle;

	}else{
		return -1;
	}

	return 0;
}

void irq_enable(void)
{
	__asm__ __volatile__(
		"mrs r0, cpsr\n"
		"bic r0, r0, #0x80\n"
		"msr cpsr, r0\n"
		:
		:
		:"r0"
	);
}

void irq_disable(void)
{
	__asm__ __volatile__(
                  "mrs r0, cpsr\n"
                  "orr r0, r0, #0x80\n"
                  "msr cpsr, r0\n"
                  :
                  :
                  :"r0"
   	);      
}
