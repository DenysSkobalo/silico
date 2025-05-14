	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 15, 2
	.globl	_print_binary                   ; -- Begin function print_binary
	.p2align	2
_print_binary:                          ; @print_binary
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	w0, [x29, #-4]
	stur	w1, [x29, #-8]
	ldur	w8, [x29, #-8]
	subs	w8, w8, #1
	stur	w8, [x29, #-12]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-12]
	subs	w8, w8, #0
	cset	w8, lt
	tbnz	w8, #0, LBB0_4
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	w8, [x29, #-4]
	ldur	w10, [x29, #-12]
	mov	w9, #1                          ; =0x1
	lsl	w9, w9, w10
	ands	w8, w8, w9
	cset	w10, ne
	mov	w9, #48                         ; =0x30
	mov	w8, #49                         ; =0x31
	and	w10, w10, #0x1
	ands	w10, w10, #0x1
	csel	w10, w8, w9, ne
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldur	w8, [x29, #-12]
	subs	w8, w8, #1
	stur	w8, [x29, #-12]
	b	LBB0_1
LBB0_4:
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_print_cpu                      ; -- Begin function print_cpu
	.p2align	2
_print_cpu:                             ; @print_cpu
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #4]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #8]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #12]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.6@PAGE
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #16]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.7@PAGE
	add	x0, x0, l_.str.7@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #20]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.8@PAGE
	add	x0, x0, l_.str.8@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #24]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.9@PAGE
	add	x0, x0, l_.str.9@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #28]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.10@PAGE
	add	x0, x0, l_.str.10@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #32]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.11@PAGE
	add	x0, x0, l_.str.11@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #36]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.12@PAGE
	add	x0, x0, l_.str.12@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #40]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.13@PAGE
	add	x0, x0, l_.str.13@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #44]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.14@PAGE
	add	x0, x0, l_.str.14@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #48]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.15@PAGE
	add	x0, x0, l_.str.15@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #52]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.16@PAGE
	add	x0, x0, l_.str.16@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #56]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.17@PAGE
	add	x0, x0, l_.str.17@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w9, [x8, #60]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.18@PAGE
	add	x0, x0, l_.str.18@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.19@PAGE
	add	x0, x0, l_.str.19@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w8, [x8, #64]
	and	w14, w8, #0x1
	ldur	x8, [x29, #-8]
	ldr	w8, [x8, #64]
	lsr	w8, w8, #1
	and	w13, w8, #0x1
	ldur	x8, [x29, #-8]
	ldr	w8, [x8, #64]
	lsr	w8, w8, #2
	and	w12, w8, #0x1
	ldur	x8, [x29, #-8]
	ldr	w8, [x8, #64]
	lsr	w8, w8, #3
	and	w11, w8, #0x1
	ldur	x8, [x29, #-8]
	ldr	w8, [x8, #64]
	lsr	w8, w8, #4
	and	w10, w8, #0x1
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x14
	str	x8, [x9]
                                        ; implicit-def: $x8
	mov	x8, x13
	str	x8, [x9, #8]
                                        ; implicit-def: $x8
	mov	x8, x12
	str	x8, [x9, #16]
                                        ; implicit-def: $x8
	mov	x8, x11
	str	x8, [x9, #24]
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9, #32]
	adrp	x0, l_.str.20@PAGE
	add	x0, x0, l_.str.20@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-8]
	ldr	w8, [x8, #64]
	lsr	w8, w8, #8
	and	w13, w8, #0x1
	ldur	x8, [x29, #-8]
	ldr	w8, [x8, #64]
	lsr	w8, w8, #9
	and	w12, w8, #0x1
	ldur	x8, [x29, #-8]
	ldr	w8, [x8, #64]
	lsr	w8, w8, #10
	and	w11, w8, #0x1
	ldur	x8, [x29, #-8]
	ldr	w8, [x8, #64]
	lsr	w8, w8, #16
	and	w10, w8, #0x1f
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x13
	str	x8, [x9]
                                        ; implicit-def: $x8
	mov	x8, x12
	str	x8, [x9, #8]
                                        ; implicit-def: $x8
	mov	x8, x11
	str	x8, [x9, #16]
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9, #24]
	adrp	x0, l_.str.21@PAGE
	add	x0, x0, l_.str.21@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%c"

l_.str.1:                               ; @.str.1
	.asciz	"\n"

l_.str.2:                               ; @.str.2
	.asciz	"\n=== ARM CPU STATE ===\n"

l_.str.3:                               ; @.str.3
	.asciz	"R0  = 0x%08X\n"

l_.str.4:                               ; @.str.4
	.asciz	"R1  = 0x%08X\n"

l_.str.5:                               ; @.str.5
	.asciz	"R2  = 0x%08X\n"

l_.str.6:                               ; @.str.6
	.asciz	"R3  = 0x%08X\n"

l_.str.7:                               ; @.str.7
	.asciz	"R4  = 0x%08X\n"

l_.str.8:                               ; @.str.8
	.asciz	"R5  = 0x%08X\n"

l_.str.9:                               ; @.str.9
	.asciz	"R6  = 0x%08X\n"

l_.str.10:                              ; @.str.10
	.asciz	"R7  = 0x%08X\n"

l_.str.11:                              ; @.str.11
	.asciz	"R8  = 0x%08X\n"

l_.str.12:                              ; @.str.12
	.asciz	"R9  = 0x%08X\n"

l_.str.13:                              ; @.str.13
	.asciz	"R10 = 0x%08X\n"

l_.str.14:                              ; @.str.14
	.asciz	"R11 = 0x%08X\n"

l_.str.15:                              ; @.str.15
	.asciz	"R12 = 0x%08X\n"

l_.str.16:                              ; @.str.16
	.asciz	"SP  = 0x%08X\n"

l_.str.17:                              ; @.str.17
	.asciz	"LR  = 0x%08X\n"

l_.str.18:                              ; @.str.18
	.asciz	"PC  = 0x%08X\n"

l_.str.19:                              ; @.str.19
	.asciz	"\nCPSR FLAGS:\n"

l_.str.20:                              ; @.str.20
	.asciz	"  N=%d Z=%d C=%d V=%d Q=%d\n"

l_.str.21:                              ; @.str.21
	.asciz	"  I=%d F=%d T=%d MODE=0x%02X\n"

.subsections_via_symbols
