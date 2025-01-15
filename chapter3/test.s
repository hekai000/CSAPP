	.file	"test.c"
	.text
	.globl	switch_eg
	.type	switch_eg, @function
switch_eg:
.LFB23:
	.cfi_startproc
	endbr64
	cmpq	$6, %rsi
	ja	.L8
	leaq	.L4(%rip), %rcx
	movslq	(%rcx,%rsi,4), %rax
	addq	%rcx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L7-.L4
	.long	.L8-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.long	.L8-.L4
	.long	.L3-.L4
	.text
.L7:
	leaq	(%rdi,%rdi,2), %rax
	leaq	(%rdi,%rax,4), %rdi
.L2:
	movq	%rdi, (%rdx)
	ret
.L6:
	addq	$10, %rdi
	jmp	.L2
.L5:
	addq	$11, %rdi
	jmp	.L2
.L3:
	addq	$11, %rdi
	jmp	.L2
.L8:
	movl	$0, %edi
	jmp	.L2
	.cfi_endproc
.LFE23:
	.size	switch_eg, .-switch_eg
	.globl	Q
	.type	Q, @function
Q:
.LFB24:
	.cfi_startproc
	endbr64
	leaq	(%rdi,%rdi), %rax
	ret
	.cfi_endproc
.LFE24:
	.size	Q, .-Q
	.globl	P
	.type	P, @function
P:
.LFB25:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	movq	%rsi, %rdi
	call	Q
	movq	%rax, %rbx
	movq	%rbp, %rdi
	call	Q
	addq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE25:
	.size	P, .-P
	.globl	rfact
	.type	rfact, @function
rfact:
.LFB26:
	.cfi_startproc
	endbr64
	cmpq	$1, %rdi
	jg	.L19
	movl	$1, %eax
	ret
.L19:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	leaq	-1(%rdi), %rdi
	call	rfact
	imulq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE26:
	.size	rfact, .-rfact
	.globl	main
	.type	main, @function
main:
.LFB27:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$3, %edi
	call	rfact
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE27:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
