	.file	"rSum.c"
	.text
	.globl	rSum
	.type	rSum, @function
rSum:
.LFB0:

	pushq	%rbp                      pushl %ebp           					  
	movq	%rsp, %rbp                rrmovl %esp, %ebp                                
	pushq	%rbx                      pushl %ebx
	subq	$24, %rsp				  irmovl $24, %ebx
       								  subl %ebx, %esp
	movq	%rdi, -24(%rbp)           rmmovl %edi, -24(%ebp)      //      edi = start     ebp-24                 
	movl	%esi, -28(%rbp)           rmmovl %esi, -28(%ebp)      //      esi  = count    ebp-28             
	cmpl	$0, -28(%rbp)             mrmovl -28(%ebp), %eax
	                                  andl %eax, %eax
	jg	.L2						      jg .L2 	
	movl	$0, %eax                  irmovl $0, %eax                                   
	jmp	.L3                           jmp .L3
.L2:
	movq	-24(%rbp), %rax           mrmovl -24(%ebp), %eax                            
	movl	(%rax), %ebx              mrmovl (%eax), %ebx                                
	movl	-28(%rbp), %eax	          mrmovl -28(%ebp), %eax                            
	leal	-1(%rax), %edx            mrmovl -1(%eax), %edx                              
	movq	-24(%rbp), %rax           mrmovl -24(%ebp), %eax                            
	addq	$4, %rax                  irmovl $4, %eax                                   
	movl	%edx, %esi
	movq	%rax, %rdi
	call	rSum
	addl	%ebx, %eax
.L3:
	movq	-8(%rbp), %rbx
	leave
	ret

