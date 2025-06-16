#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "include/memory.h"
#include "include/cpu.h"

static const uint32_t program[] = {
    // MOVZ X1, #0x2
    0xD2800041,

    // MOVZ X2, #0x3
    0xD2800062,

    // ADD X3, X1, X2 => X3 = 2 + 3 = 5
    0x8B020063,

    // ADDI X3, X3, #10 => X3 = 5 + 10 = 15
    0x91002863,

    // SUB X4, X3, X1 => X4 = 15 - 2 = 13
    0xCB010064,

    // SUBI X5, X4, #3 => X5 = 13 - 3 = 10
    0xD1000C85,

    // MUL X6, X1, X2 => X6 = 2 * 3 = 6
    0x9B027C26,

    // AND X7, X3, X5 => 15 & 10 = 0xA
    0x8A050067,

    // ORR X8, X3, X5 => 15 | 10 = 0xF
    0xAA050068,

    // EOR X9, X3, X5 => 15 ^ 10 = 0x5
    0xCA050069,

    // ANDI X10, X3, #0xF0 => 15 & 0xF0 = 0x00
    0x12003FEA,

    // ORRI X11, X3, #0xF0 => 15 | 0xF0 = 0xFF
    0x32003FEB,

    // EORI X12, X3, #0xF0 => 15 ^ 0xF0 = 0xEF
    0x52003FEC,

    // MOVN X13, #0x1234 => ~0x1234 = 0xFFFFFFFFFFFFEDCB
    0x928246AD,

    // MOVZ X14, #0x5678 => X14 = 0x5678
    0xD2CF0D8E,

    // MOVK X14, #0xAAAA, LSL #16 => X14 |= 0xAAAA << 16
    0xF2C955CE,

    // HLT
    0xD4400000
};

void load_program(const uint32_t *prog, size_t count) {
    for (size_t i = 0; i < count; i++) {
        memory_write32(i * 4, prog[i]);
    }
}

int main(void) {
    memory_init();

    CPU cpu;
    cpu_init(&cpu);

    load_program(program, sizeof(program) / sizeof(program[0]));
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
