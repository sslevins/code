	b reset
	b unde
	b swi
	b pre_bot
	b dat_bot
	.word 0x00
	b irq
	b fiq
reset:
	mov r0, #0x70000000
	orr r0, r0, #0x13
	mcr p15, 0, r0, c15, c2, 4

	mov sp, #0x2000
	bl arm_boot
here:
	b here
unde:
swi:
pre_bot:
dat_bot:
irq:
fiq:

	
	
