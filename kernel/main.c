#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "include/memory.h"
#include "include/cpu.h"

// static const uint32_t program[] = {
//     // MOVZ: X1 = 0x0002, X2 = 0x0003
//     0xD2800041, // MOVZ X1, #0x2
//     0xD2800062, // MOVZ X2, #0x3
//
//     // ADD: X3 = X1 + X2 = 5
//     0x8B020023, // ADD X3, X1, X2
//
//     // SUB: X5 = X2 - X1 = 1
//     0xCB010045, // SUB X5, X2, X1
//
//     // MUL: X7 = X1 * X2 = 6
//     0x9B027C27, // MUL X7, X1, X2
//
//     // Logical R-type
//     0x8A01002A, // AND X10, X1, X1 → 0x2
//     0xAA01002B, // ORR X11, X1, X1 → 0x2
//     0xCA01002C, // EOR X12, X1, X1 → 0x0
//
//     // MOVK: X14 = set upper halfword
//     0xF2A0000E, // MOVK X14, #0x0, LSL #32 (keeps zero)
//
//     // MOVN: X15 = ~0x3 = 0xFFFFFFFFFFFFFFFC
//     0x9280060F, // MOVN X15, #0x3
//
//     // HLT
//     0xD4400000  // HLT
// };

extern const uint8_t program_bytes[];
extern const size_t program_size_bytes;

void load_program() {
    for (size_t i = 0; i < program_size_bytes; i += 4) {
        uint32_t instr = program_bytes[i] |
                         (program_bytes[i + 1] << 8) |
                         (program_bytes[i + 2] << 16) |
                         (program_bytes[i + 3] << 24);
        memory_write32(i, instr);
    }
}

int main(void) {
    memory_init();

    CPU cpu;
    cpu_init(&cpu);

    load_program();
    cpu.pc = 0x00;

    size_t cycles = 0;
    while (!cpu.halted) {
        cpu_tick(&cpu);
        cycles++;
    }

    printf("\n=== CPU Halted after %zu cycles ===\n", cycles);
    cpu_dump(&cpu);

    return 0;
}
