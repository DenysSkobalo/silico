#include <stdio.h>
#include <string.h>
#include "../../cpu/include/cpu.h"

void init_cpu(CPUState_t *cpu, uint64_t reset_vector) {
    memset(cpu->X, 0, sizeof(cpu->X));
    cpu->SP = 0;
    cpu->PC = reset_vector;

    cpu->PSTATE.N = 0;
    cpu->PSTATE.Z = 0;
    cpu->PSTATE.C = 0;
    cpu->PSTATE.V = 0;
    cpu->PSTATE.EL = EL1;
    cpu->PSTATE.I = 0;
    cpu->PSTATE.F = 0;
    cpu->PSTATE.D = 0;
}

void cpu_dump(const CPUState_t *cpu) {
        printf("=== CPU Dump ===\n");
    for (int i = 0; i < 31; i++) {
        printf("X%2d = 0x%016llx\n", i, cpu->X[i]);
    }
    printf(" SP = 0x%016llx\n", cpu->SP);
    printf(" PC = 0x%016llx\n", cpu->PC);
    printf("Flags: N=%d Z=%d C=%d V=%d  EL=%d\n",
           cpu->PSTATE.N, cpu->PSTATE.Z,
           cpu->PSTATE.C, cpu->PSTATE.V,
           cpu->PSTATE.EL);
    printf("================\n");
}
