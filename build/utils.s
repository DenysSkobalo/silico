	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 15, 2
	.globl	_print_binary                   ; -- Begin function print_binary
	.p2align	2
_print_binary:                          ; @print_binary
	.cfi_startproc
; %bb.0:
	cmp	w1, #1
	b.lt	LBB0_4
; %bb.1:
	stp	x22, x21, [sp, #-48]!           ; 16-byte Folded Spill
	stp	x20, x19, [sp, #16]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	mov	x19, x0
	add	w20, w1, #1
	mov	w21, #48                        ; =0x30
LBB0_2:                                 ; =>This Inner Loop Header: Depth=1
	sub	w8, w20, #2
	lsr	w8, w19, w8
	tst	w8, #0x1
	cinc	w0, w21, ne
	bl	_putchar
	sub	w20, w20, #1
	cmp	w20, #1
	b.hi	LBB0_2
; %bb.3:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #16]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp], #48             ; 16-byte Folded Reload
LBB0_4:
	mov	w0, #10                         ; =0xa
	b	_putchar
	.cfi_endproc
                                        ; -- End function
	.globl	_print_cpu                      ; -- Begin function print_cpu
	.p2align	2
_print_cpu:                             ; @print_cpu
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x20, x19, [sp, #48]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	mov	x19, x0
Lloh0:
	adrp	x0, l_str@PAGE
Lloh1:
	add	x0, x0, l_str@PAGEOFF
	bl	_puts
	ldr	w8, [x19]
	str	x8, [sp]
Lloh2:
	adrp	x0, l_.str.3@PAGE
Lloh3:
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #4]
	str	x8, [sp]
Lloh4:
	adrp	x0, l_.str.4@PAGE
Lloh5:
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #8]
	str	x8, [sp]
Lloh6:
	adrp	x0, l_.str.5@PAGE
Lloh7:
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #12]
	str	x8, [sp]
Lloh8:
	adrp	x0, l_.str.6@PAGE
Lloh9:
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #16]
	str	x8, [sp]
Lloh10:
	adrp	x0, l_.str.7@PAGE
Lloh11:
	add	x0, x0, l_.str.7@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #20]
	str	x8, [sp]
Lloh12:
	adrp	x0, l_.str.8@PAGE
Lloh13:
	add	x0, x0, l_.str.8@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #24]
	str	x8, [sp]
Lloh14:
	adrp	x0, l_.str.9@PAGE
Lloh15:
	add	x0, x0, l_.str.9@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #28]
	str	x8, [sp]
Lloh16:
	adrp	x0, l_.str.10@PAGE
Lloh17:
	add	x0, x0, l_.str.10@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #32]
	str	x8, [sp]
Lloh18:
	adrp	x0, l_.str.11@PAGE
Lloh19:
	add	x0, x0, l_.str.11@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #36]
	str	x8, [sp]
Lloh20:
	adrp	x0, l_.str.12@PAGE
Lloh21:
	add	x0, x0, l_.str.12@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #40]
	str	x8, [sp]
Lloh22:
	adrp	x0, l_.str.13@PAGE
Lloh23:
	add	x0, x0, l_.str.13@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #44]
	str	x8, [sp]
Lloh24:
	adrp	x0, l_.str.14@PAGE
Lloh25:
	add	x0, x0, l_.str.14@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #48]
	str	x8, [sp]
Lloh26:
	adrp	x0, l_.str.15@PAGE
Lloh27:
	add	x0, x0, l_.str.15@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #52]
	str	x8, [sp]
Lloh28:
	adrp	x0, l_.str.16@PAGE
Lloh29:
	add	x0, x0, l_.str.16@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #56]
	str	x8, [sp]
Lloh30:
	adrp	x0, l_.str.17@PAGE
Lloh31:
	add	x0, x0, l_.str.17@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #60]
	str	x8, [sp]
Lloh32:
	adrp	x0, l_.str.18@PAGE
Lloh33:
	add	x0, x0, l_.str.18@PAGEOFF
	bl	_printf
Lloh34:
	adrp	x0, l_str.22@PAGE
Lloh35:
	add	x0, x0, l_str.22@PAGEOFF
	bl	_puts
	ldr	w8, [x19, #64]
	lsr	w9, w8, #31
	ubfx	w10, w8, #30, #1
	ubfx	w11, w8, #29, #1
	ubfx	w12, w8, #28, #1
	ubfx	w8, w8, #27, #1
	stp	x12, x8, [sp, #24]
	stp	x10, x11, [sp, #8]
	str	x9, [sp]
Lloh36:
	adrp	x0, l_.str.20@PAGE
Lloh37:
	add	x0, x0, l_.str.20@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #64]
	ubfx	w9, w8, #7, #1
	ubfx	w10, w8, #6, #1
	ubfx	w11, w8, #5, #1
	and	w8, w8, #0x1f
	stp	x11, x8, [sp, #16]
	stp	x9, x10, [sp]
Lloh38:
	adrp	x0, l_.str.21@PAGE
Lloh39:
	add	x0, x0, l_.str.21@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.loh AdrpAdd	Lloh38, Lloh39
	.loh AdrpAdd	Lloh36, Lloh37
	.loh AdrpAdd	Lloh34, Lloh35
	.loh AdrpAdd	Lloh32, Lloh33
	.loh AdrpAdd	Lloh30, Lloh31
	.loh AdrpAdd	Lloh28, Lloh29
	.loh AdrpAdd	Lloh26, Lloh27
	.loh AdrpAdd	Lloh24, Lloh25
	.loh AdrpAdd	Lloh22, Lloh23
	.loh AdrpAdd	Lloh20, Lloh21
	.loh AdrpAdd	Lloh18, Lloh19
	.loh AdrpAdd	Lloh16, Lloh17
	.loh AdrpAdd	Lloh14, Lloh15
	.loh AdrpAdd	Lloh12, Lloh13
	.loh AdrpAdd	Lloh10, Lloh11
	.loh AdrpAdd	Lloh8, Lloh9
	.loh AdrpAdd	Lloh6, Lloh7
	.loh AdrpAdd	Lloh4, Lloh5
	.loh AdrpAdd	Lloh2, Lloh3
	.loh AdrpAdd	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
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

l_.str.20:                              ; @.str.20
	.asciz	"  N=%d Z=%d C=%d V=%d Q=%d\n"

l_.str.21:                              ; @.str.21
	.asciz	"  I=%d F=%d T=%d MODE=0x%02X\n"

l_str:                                  ; @str
	.asciz	"\n=== ARM CPU STATE ==="

l_str.22:                               ; @str.22
	.asciz	"\nCPSR FLAGS:"

.subsections_via_symbols
