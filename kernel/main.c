#include <stdio.h>
#include "include/memory.h"
#include "include/cpu.h"

int main() {
    memory_init();

    CPU cpu;
    cpu_init(&cpu);

    memory_write32(0x00, 0xD2800020);
    memory_write32(0x04, 0x91000401);
    memory_write32(0x08, 0xD4400000);

    cpu.pc = 0x00;

    while(!cpu.halted) {
        cpu_step(&cpu);
    }

    cpu_dump(&cpu);

    return 0;
}
