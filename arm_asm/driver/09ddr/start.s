.text
.global _start
.align 2
_start:
	mov r0, #0x70000000
	orr r0, r0, #0x13
	mcr p15, 0, r0, c15, c2, 4
	
	mov sp, #0x2000
	bl main
here:	b here
