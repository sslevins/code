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
pre_bot:
dat_bot:
irq:
	mov sp, #0x52000000
	stmfd sp!, {r0-r12, lr}
	bl do_irq
	ldmfd sp!, {r0-r12, lr}
	subs pc, lr, #4
fiq:
