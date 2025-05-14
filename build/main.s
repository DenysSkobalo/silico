	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 15, 2
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	stur	wzr, [x29, #-28]
	mov	w0, #48879                      ; =0xbeef
	movk	w0, #57005, lsl #16
	bl	_init_device
	stur	x0, [x29, #-24]
	stur	x1, [x29, #-16]
	ldur	x8, [x29, #-24]
	add	x0, sp, #24
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	str	x8, [sp, #24]
	ldur	w8, [x29, #-16]
	str	w8, [sp, #32]
	mov	w1, #1                          ; =0x1
	str	w1, [sp, #12]                   ; 4-byte Folded Spill
	bl	_set_status
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	bl	_print_device_register
	ldr	w1, [sp, #12]                   ; 4-byte Folded Reload
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	bl	_set_data
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	bl	_get_data
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x0
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	bl	_get_data
	mov	w1, #32                         ; =0x20
	bl	_print_binary
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	bl	_get_data
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x0
	str	x8, [x9]
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	bl	___stack_chk_fail
LBB0_2:
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"\n-------Info Regsiter------\n"

l_.str.1:                               ; @.str.1
	.asciz	"\n-------Data in Regsiter------\n"

l_.str.2:                               ; @.str.2
	.asciz	"hex: 0x%08X\n"

l_.str.3:                               ; @.str.3
	.asciz	"bin: 0b"

l_.str.4:                               ; @.str.4
	.asciz	"dec: %u\n"

.subsections_via_symbols
