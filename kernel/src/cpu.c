#include "../include/cpu.h"
#include "../include/flags.h"
#include "../include/addresses.h"

ARM_CPU init_cpu() {
    ARM_CPU cpu = {0};
    // cpu.R[15].value = 0x00000000;
    // cpu.R[13].value = 0xFFFFFFFC; 
    PCR(&cpu).value = NULL_ADDRESS;
    SPR(&cpu).value = 0xFFFFFFFC;

    cpu.CPSR = (cpu.CPSR & ~CPSR_MODE_MASK) | USER_MODE;
    return cpu;
}

uint32_t get_cpsr_value(ARM_CPU *cpu) {
    return cpu->CPSR;
}