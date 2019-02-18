	.text
	.file	"square_outline.cpp"
	.globl	_Z6squarei              # -- Begin function _Z6squarei
	.p2align	4, 0x90
	.type	_Z6squarei,@function
_Z6squarei:                             # @_Z6squarei
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi0:
	.cfi_def_cfa_offset 16
.Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi2:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	imull	-4(%rbp), %edi
	movl	%edi, %eax
	popq	%rbp
	retq
.Lfunc_end0:
	.size	_Z6squarei, .Lfunc_end0-_Z6squarei
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi3:
	.cfi_def_cfa_offset 16
.Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$1234, %edi             # imm = 0x4D2
	movl	$0, -4(%rbp)
	callq	_Z6squarei
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function

	.ident	"clang version 5.0.1-svn325091-1~exp1 (branches/release_50)"
	.section	".note.GNU-stack","",@progbits
