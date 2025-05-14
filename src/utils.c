#include "utils.h"
#include <stdio.h>

void print_binary(uint32_t value, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%c", (value & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}

void print_cpu(const ARM_CPU* cpu) {
    printf("\n=== ARM CPU STATE ===\n");
    printf("R0  = 0x%08X\n", cpu->R0.value);
    printf("R1  = 0x%08X\n", cpu->R1.value);
    printf("R2  = 0x%08X\n", cpu->R2.value);
    printf("R3  = 0x%08X\n", cpu->R3.value);
    printf("R4  = 0x%08X\n", cpu->R4.value);
    printf("R5  = 0x%08X\n", cpu->R5.value);
    printf("R6  = 0x%08X\n", cpu->R6.value);
    printf("R7  = 0x%08X\n", cpu->R7.value);
    printf("R8  = 0x%08X\n", cpu->R8.value);
    printf("R9  = 0x%08X\n", cpu->R9.value);
    printf("R10 = 0x%08X\n", cpu->R10.value);
    printf("R11 = 0x%08X\n", cpu->R11.value);
    printf("R12 = 0x%08X\n", cpu->R12.value);
    printf("SP  = 0x%08X\n", cpu->SP.value);
    printf("LR  = 0x%08X\n", cpu->LR.value);
    printf("PC  = 0x%08X\n", cpu->PC.value);
    printf("\nCPSR FLAGS:\n");
    printf("  N=%d Z=%d C=%d V=%d Q=%d\n", cpu->CPSR.N, cpu->CPSR.Z, cpu->CPSR.C, cpu->CPSR.V, cpu->CPSR.Q);
    printf("  I=%d F=%d T=%d MODE=0x%02X\n", cpu->CPSR.I, cpu->CPSR.F, cpu->CPSR.T, cpu->CPSR.MODE);
}
