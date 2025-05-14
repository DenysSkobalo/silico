#include "../include/utils.h"
#include "../include/cpu.h"
#include "../include/flags.h"
#include "../include/registers.h"
#include <stdint.h>
#include <stdio.h>

void print_binary(uint32_t value, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%c", (value & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}

void print_cpu(const ARM_CPU* cpu) {
    printf("\n=== ARM CPU STATE ===\n");

    for (int i = 0; i < 16; i++) {
        printf("R%-2d: 0x%08X\n", i, cpu->R[i].value);
    }

    printf("\nCPSR FLAGS:\n");
    printf("  N=%d Z=%d C=%d V=%d Q=%d\n", 
           (cpu->CPSR & CPSR_FLAG_N) != 0, 
           (cpu->CPSR & CPSR_FLAG_Z) != 0, 
           (cpu->CPSR & CPSR_FLAG_C) != 0, 
           (cpu->CPSR & CPSR_FLAG_V) != 0, 
           (cpu->CPSR & CPSR_FLAG_Q) != 0);
    printf("  I=%d F=%d T=%d MODE=0x%02X\n", 
           (cpu->CPSR & CPSR_FLAG_I) != 0, 
           (cpu->CPSR & CPSR_FLAG_F) != 0, 
           (cpu->CPSR & CPSR_FLAG_T) != 0, 
           cpu->CPSR & CPSR_MODE_MASK);
}
