	b reset
	b unde
	b swi
	b pre_bot
	b dat_bot
	.word 0x00
	ldr pc, _irq
	b fiq
_irq:
	.word irq
reset:
	stmfd sp!, {r0-r12, lr}
	mov r0, #0x50000000
	mov r1, #0
	mov r2, #60
loop:
	ldr r3, [r0], #4
	str r3, [r1], #4
	cmp r1, r2
	blt loop
	bl main
	ldmfd sp!, {r0-r12, pc}
unde:
swi:
pre_bot:
dat_bot:
fiq:
irq:
	mov sp, #0x52000000
	stmfd sp!, {r0-r12, lr}
	bl do_irq
	ldmfd sp!, {r0-r12, lr}
	subs pc, lr, #4
