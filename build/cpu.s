	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 15, 2
	.globl	_init_cpu                       ; -- Begin function init_cpu
	.p2align	2
_init_cpu:                              ; @init_cpu
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	x0, x8
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	mov	x2, #72                         ; =0x48
	mov	w1, #0                          ; =0x0
	bl	_memset
	ldr	x9, [sp, #8]                    ; 8-byte Folded Reload
	str	wzr, [x9, #60]
	mov	w8, #-4                         ; =0xfffffffc
	str	w8, [x9, #52]
	ldr	w8, [x9, #64]
	and	w8, w8, #0xffe0ffff
	orr	w8, w8, #0x100000
	str	w8, [x9, #64]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
