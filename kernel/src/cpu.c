#include "../include/cpu.h"

ARM_CPU init_cpu() {
    ARM_CPU cpu = {0};
    cpu.PC.value = 0x00000000;
    cpu.SP.value = 0xFFFFFFFC;
    cpu.CPSR = (cpu.CPSR & ~CPSR_MODE_MASK) | 0b10000; // User mode
    return cpu;
}

uint32_t get_cpsr_value(ARM_CPU *cpu) {
    return cpu->CPSR;
}