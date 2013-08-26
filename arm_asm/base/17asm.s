.text
.align 2
.global main
main:
	stmfd sp!, {r0-r12, lr}
	ldr r0, =string
	bl printf	
	ldmfd sp!, {r0-r12, pc}
.data
data:
	.word 0x123
data1:
	.short 0x12, 0x34
data2:
	.byte 0x1, 0x2
string:
	.asciz "hello arm\n"
.bss
.section .abc
.space 100, 0xff
	
