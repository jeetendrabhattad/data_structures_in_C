	.file	"postfix_evaluate.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"\nEnter the postfix expression:-"
.LC1:
	.string	"%[^\n]s"
.LC2:
	.string	"\n Expression is %s"
.LC3:
	.string	"\n Pushing %d"
.LC4:
	.string	"\nLogic result = %d"
.LC5:
	.string	"\n Addition is %d \n"
.LC6:
	.string	"\n Multiplication is %d \n"
.LC7:
	.string	"\n Subtraction is %d \n"
.LC8:
	.string	"\n Divsion is %d \n"
.LC9:
	.string	"Final Result = %d\n"
	.text
	.globl	EvaluatePostfix
	.type	EvaluatePostfix, @function
EvaluatePostfix:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$164, %esp
	.cfi_offset 3, -12
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	$.LC0, (%esp)
	call	printf
	leal	-112(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	__isoc99_scanf
	leal	-112(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$0, -148(%ebp)
	movl	$0, -144(%ebp)
	movl	$10, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	InitStack
	jmp	.L2
.L12:
	call	__ctype_b_loc
	movl	(%eax), %eax
	leal	-112(%ebp), %ecx
	movl	-148(%ebp), %edx
	addl	%ecx, %edx
	movzbl	(%edx), %edx
	movsbl	%dl, %edx
	addl	%edx, %edx
	addl	%edx, %eax
	movzwl	(%eax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	je	.L3
	leal	-112(%ebp), %edx
	movl	-148(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	leal	-112(%ebp), %edx
	movl	-148(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Push
	addl	$1, -148(%ebp)
	jmp	.L4
.L6:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Pop
	movl	%eax, -144(%ebp)
	movl	-144(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	leal	-112(%ebp), %ecx
	movl	-148(%ebp), %edx
	addl	%ecx, %edx
	movzbl	(%edx), %edx
	movsbl	%dl, %edx
	subl	$48, %edx
	addl	%edx, %eax
	movl	%eax, -144(%ebp)
	movl	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Push
	addl	$1, -148(%ebp)
.L4:
	leal	-112(%ebp), %edx
	movl	-148(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	je	.L5
	call	__ctype_b_loc
	movl	(%eax), %eax
	leal	-112(%ebp), %ecx
	movl	-148(%ebp), %edx
	addl	%ecx, %edx
	movzbl	(%edx), %edx
	movsbl	%dl, %edx
	addl	%edx, %edx
	addl	%edx, %eax
	movzwl	(%eax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	jne	.L6
	jmp	.L5
.L3:
	leal	-112(%ebp), %edx
	movl	-148(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	cmpl	$43, %eax
	je	.L7
	cmpl	$43, %eax
	jg	.L8
	cmpl	$42, %eax
	je	.L9
	jmp	.L5
.L8:
	cmpl	$45, %eax
	je	.L10
	cmpl	$47, %eax
	je	.L11
	jmp	.L5
.L7:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Pop
	movl	%eax, %ebx
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Pop
	addl	%ebx, %eax
	movl	%eax, -144(%ebp)
	movl	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC5, (%esp)
	call	printf
	movl	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Push
	jmp	.L5
.L9:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Pop
	movl	%eax, %ebx
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Pop
	imull	%ebx, %eax
	movl	%eax, -144(%ebp)
	movl	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	movl	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Push
	jmp	.L5
.L10:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Pop
	movl	%eax, -140(%ebp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Pop
	movl	%eax, -136(%ebp)
	movl	-140(%ebp), %eax
	movl	-136(%ebp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -144(%ebp)
	movl	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC7, (%esp)
	call	printf
	movl	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Push
	jmp	.L5
.L11:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Pop
	movl	%eax, -132(%ebp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Pop
	movl	%eax, -128(%ebp)
	movl	-128(%ebp), %eax
	cltd
	idivl	-132(%ebp)
	movl	%eax, -144(%ebp)
	movl	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC8, (%esp)
	call	printf
	movl	-144(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Push
	nop
.L5:
	addl	$1, -148(%ebp)
.L2:
	leal	-112(%ebp), %edx
	movl	-148(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L12
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	Pop
	movl	%eax, 4(%esp)
	movl	$.LC9, (%esp)
	call	printf
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	DeInitStack
	movl	-12(%ebp), %eax
	xorl	%gs:20, %eax
	je	.L13
	call	__stack_chk_fail
.L13:
	addl	$164, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	EvaluatePostfix, .-EvaluatePostfix
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	EvaluatePostfix
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
