	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 15, 2
	.globl	_init_device                    ; -- Begin function init_device
	.p2align	2
_init_device:                           ; @init_device
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
	str	w0, [sp, #24]
	mov	w8, #1                          ; =0x1
	strb	w8, [sp, #28]
	strb	w8, [sp, #29]
	strh	wzr, [sp, #30]
	ldr	w8, [sp, #24]
	str	w8, [sp, #32]
	ldur	x8, [sp, #28]
	stur	x8, [x29, #-24]
	ldr	w8, [sp, #36]
	stur	w8, [x29, #-16]
	ldur	x8, [x29, #-24]
	str	x8, [sp, #8]                    ; 8-byte Folded Spill
	ldur	x8, [x29, #-16]
	str	x8, [sp, #16]                   ; 8-byte Folded Spill
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
	ldr	x1, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_set_status                     ; -- Begin function set_status
	.p2align	2
_set_status:                            ; @set_status
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	strh	w1, [sp, #6]
	ldrh	w10, [sp, #6]
	ldr	x9, [sp, #8]
	ldrb	w8, [x9]
	orr	w8, w8, w10
	strb	w8, [x9]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_clear_status                   ; -- Begin function clear_status
	.p2align	2
_clear_status:                          ; @clear_status
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	strb	w1, [sp, #7]
	ldrb	w10, [sp, #7]
	ldr	x9, [sp, #8]
	ldrb	w8, [x9]
	bic	w8, w8, w10
	strb	w8, [x9]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_set_data                       ; -- Begin function set_data
	.p2align	2
_set_data:                              ; @set_data
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	w1, [sp, #4]
	ldr	w8, [sp, #4]
	ldr	x9, [sp, #8]
	str	w8, [x9, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_get_data                       ; -- Begin function get_data
	.p2align	2
_get_data:                              ; @get_data
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	ldr	x8, [sp, #8]
	ldr	w0, [x8, #8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_print_device_register          ; -- Begin function print_device_register
	.p2align	2
_print_device_register:                 ; @print_device_register
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	ldrb	w10, [x8]
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldrb	w0, [x8]
	mov	w1, #8                          ; =0x8
	stur	w1, [x29, #-12]                 ; 4-byte Folded Spill
	bl	_print_binary
	ldur	x8, [x29, #-8]
	ldrb	w10, [x8, #1]
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	ldur	w1, [x29, #-12]                 ; 4-byte Folded Reload
	ldur	x8, [x29, #-8]
	ldrb	w0, [x8, #1]
	bl	_print_binary
	ldur	x8, [x29, #-8]
	ldrh	w10, [x8, #2]
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldrh	w0, [x8, #2]
	mov	w1, #16                         ; =0x10
	bl	_print_binary
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #4]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w0, [x8, #4]
	mov	w1, #32                         ; =0x20
	bl	_print_binary
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Register Status: 0x%02X (binary): "

l_.str.1:                               ; @.str.1
	.asciz	"Register Control: 0x%02X (binary): "

l_.str.2:                               ; @.str.2
	.asciz	"Register Error Code: 0x%04X (binary): "

l_.str.3:                               ; @.str.3
	.asciz	"Register Address: 0x%08X (binary): "

.subsections_via_symbols
