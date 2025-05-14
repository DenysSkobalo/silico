	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 15, 2
	.globl	_init_cpu                       ; -- Begin function init_cpu
	.p2align	2
_init_cpu:                              ; @init_cpu
	.cfi_startproc
; %bb.0:
	movi.2d	v0, #0000000000000000
	stp	q0, q0, [x8, #32]
	stp	q0, q0, [x8]
	mov	w9, #-4                         ; =0xfffffffc
	str	w9, [x8, #52]
	mov	w9, #16                         ; =0x10
	str	w9, [x8, #64]
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_get_cpsr_value                 ; -- Begin function get_cpsr_value
	.p2align	2
_get_cpsr_value:                        ; @get_cpsr_value
	.cfi_startproc
; %bb.0:
	ldr	w0, [x0, #64]
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
