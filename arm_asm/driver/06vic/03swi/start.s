.text
.global _start
.align 2
_start:
	b reset
	b unde
	b swi
	b pre_bot
	b dat_bot
	.word 0x00
	b irq
	b fiq
reset:
	stmfd sp!, {r0-r12, lr}
	bl main
	ldmfd sp!, {r0-r12, pc}
unde:
swi:
	stmfd sp!, {r0-r12, lr}
	sub r0,lr,#4
	bl do_swi
	ldmfd sp!, {r0-r12, lr}
	
	movs pc, lr
pre_bot:
dat_bot:
irq:
fiq:
