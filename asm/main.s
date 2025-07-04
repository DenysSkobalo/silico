# .text
# .global _start
#
# _start:
#     mov x1, #3
#     mov x2, #3
#     add x3, x1, x2
#     hlt #0

.text
.global _start

_start:
    movz x1, #0x2         // x1 := 0x0002
    movz x2, #0x3         // x2 := 0x0003

    add x3, x1, x2        // x3 := x1 + x2 = 5
    sub x4, x3, x1        // x4 := x3 - x1 = 3
    mul x5, x1, x2        // x5 := x1 * x2 = 6

    and x6, x3, x4        // x6 := 5 & 3 = 1
    orr x7, x3, x4        // x7 := 5 | 3 = 7
    eor x8, x3, x4        // x8 := 5 ^ 3 = 6

    movz x9, #0xABCD      // x9 := 0x0000ABCD
    movk x9, #0x1234, lsl #16 // x9 := x9 | (0x1234 << 16)
    movk x9, #0xDEAD, lsl #32 // x9 := x9 | (0xDEAD << 32)

    movn x10, #0x0        // x10 := ~0 = 0xFFFFFFFFFFFFFFFF

    hlt #0
