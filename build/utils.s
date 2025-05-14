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
	stp	xzr, x8, [sp]
Lloh2:
	adrp	x20, l_.str.3@PAGE
Lloh3:
	add	x20, x20, l_.str.3@PAGEOFF
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #4]
	mov	w9, #1                          ; =0x1
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #8]
	mov	w9, #2                          ; =0x2
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #12]
	mov	w9, #3                          ; =0x3
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #16]
	mov	w9, #4                          ; =0x4
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #20]
	mov	w9, #5                          ; =0x5
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #24]
	mov	w9, #6                          ; =0x6
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #28]
	mov	w9, #7                          ; =0x7
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #32]
	mov	w9, #8                          ; =0x8
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #36]
	mov	w9, #9                          ; =0x9
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #40]
	mov	w9, #10                         ; =0xa
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #44]
	mov	w9, #11                         ; =0xb
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #48]
	mov	w9, #12                         ; =0xc
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #52]
	mov	w9, #13                         ; =0xd
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #56]
	mov	w9, #14                         ; =0xe
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
	ldr	w8, [x19, #60]
	mov	w9, #15                         ; =0xf
	stp	x9, x8, [sp]
	mov	x0, x20
	bl	_printf
Lloh4:
	adrp	x0, l_str.7@PAGE
Lloh5:
	add	x0, x0, l_str.7@PAGEOFF
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
Lloh6:
	adrp	x0, l_.str.5@PAGE
Lloh7:
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	ldr	w8, [x19, #64]
	ubfx	w9, w8, #7, #1
	ubfx	w10, w8, #6, #1
	ubfx	w11, w8, #5, #1
	and	w8, w8, #0x1f
	stp	x11, x8, [sp, #16]
	stp	x9, x10, [sp]
Lloh8:
	adrp	x0, l_.str.6@PAGE
Lloh9:
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.loh AdrpAdd	Lloh8, Lloh9
	.loh AdrpAdd	Lloh6, Lloh7
	.loh AdrpAdd	Lloh4, Lloh5
	.loh AdrpAdd	Lloh2, Lloh3
	.loh AdrpAdd	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str.3:                               ; @.str.3
	.asciz	"R%-2d: 0x%08X\n"

l_.str.5:                               ; @.str.5
	.asciz	"  N=%d Z=%d C=%d V=%d Q=%d\n"

l_.str.6:                               ; @.str.6
	.asciz	"  I=%d F=%d T=%d MODE=0x%02X\n"

l_str:                                  ; @str
	.asciz	"\n=== ARM CPU STATE ==="

l_str.7:                                ; @str.7
	.asciz	"\nCPSR FLAGS:"

.subsections_via_symbols
