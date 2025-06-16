#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "include/memory.h"
#include "include/cpu.h"

static const uint32_t program[] = {
    0xD2800041, // MOVZ X1, #0x2
    0xD2800062, // MOVZ X2, #0x3
    0x8B020020, // ADD  X0, X1, X2
    0x91001000, // ADDI X0, X0, #0x4
    0xD4400000  // HLT
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
