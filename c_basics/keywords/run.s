	.file	"run_temp.c"
	.option nopic
	.attribute arch, "rv32i2p1"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	__adddf3
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-48
	sw	ra,44(sp)
	sw	s0,40(sp)
	addi	s0,sp,48
	lui	a5,%hi(.LC0)
	lw	a4,%lo(.LC0)(a5)
	lw	a5,%lo(.LC0+4)(a5)
	sw	a4,-24(s0)
	sw	a5,-20(s0)
	lui	a5,%hi(.LC1)
	lw	a4,%lo(.LC1)(a5)
	lw	a5,%lo(.LC1+4)(a5)
	sw	a4,-32(s0)
	sw	a5,-28(s0)
	lw	a2,-32(s0)
	lw	a3,-28(s0)
	lw	a0,-24(s0)
	lw	a1,-20(s0)
	call	__adddf3
	mv	a4,a0
	mv	a5,a1
	sw	a4,-40(s0)
	sw	a5,-36(s0)
	lw	a4,-40(s0)
	lw	a5,-36(s0)
	mv	a0,a4
	mv	a1,a5
	lw	ra,44(sp)
	lw	s0,40(sp)
	addi	sp,sp,48
	jr	ra
	.size	main, .-main
	.align	2
	.globl	printf
	.type	printf, @function
printf:
	addi	sp,sp,-16
	sw	s0,12(sp)
	addi	s0,sp,16
	nop
	lw	s0,12(sp)
	addi	sp,sp,16
	jr	ra
	.size	printf, .-printf
	.section	.rodata
	.align	3
.LC0:
	.word	0
	.word	1072693248
	.align	3
.LC1:
	.word	0
	.word	-1073741824
	.ident	"GCC: (12.2.0-14+11+b1) 12.2.0"
