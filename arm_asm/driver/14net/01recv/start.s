	b reset
	b unde
	b swi
	b pre_bot
	b dat_bot
	.word 0x00
	ldr pc, =irq
	b fiq

reset:
	stmfd sp!, {r0-r12, lr}
	mov r0, #0
	mov r1, #0x50000000
loop:
	ldr r2, [r1], #4
	str r2, [r0], #4
	cmp r0, #60
	blt loop
	bl main
	ldmfd sp!, {r0-r12, pc}
unde:
swi:
pre_bot:
dat_bot:
irq:
	stmfd sp!, {r0-r12, lr}
	bl do_irq
	ldmfd sp!, {r0-r12, lr}
	subs pc, lr, #4
fiq:
