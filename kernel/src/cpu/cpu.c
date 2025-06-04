#include <stdio.h>
#include <string.h>
#include "../../include/cpu.h"
#include "../../include/memory.h"

#define RESET_VECTOR 0x0
#define BITS(val, hi, lo) (((val) >> (lo)) & ((1ULL << ((hi)-(lo)+1)) - 1)) // Extract bits helper macro
#define OPCODE_MASK    0xFFC00000
#define OPCODE_MOVZ    0xD2800000  // MOVZ Xd, #imm
#define OPCODE_ADD_IMM 0x91000000  // ADD Xd, Xn, #imm
#define OPCODE_HLT     0xD4400000  // HLT (exception)

void cpu_init(CPU *cpu) {
    if(!cpu) return;

    memset(cpu, 0, sizeof(CPU));

    for (int i=0; i<NUM_GP_REGS; i++) {
        cpu->x[i] = 0;
    }

    cpu->sp = RESET_VECTOR;
    cpu->pc = RESET_VECTOR;

    cpu->pstate.N = 0;
    cpu->pstate.Z = 0;
    cpu->pstate.C = 0;
    cpu->pstate.V = 0;
    cpu->pstate.D = 0;
    cpu->pstate.A = 0;
    cpu->pstate.I = 0;
    cpu->pstate.F = 0;
    cpu->pstate.IL = 0;
    cpu->pstate.SS = 0;

    cpu->current_el = 1;

    for (int el = 0; el<NUM_EL; ++el) {
        cpu->el[el].sp     = 0;
        cpu->el[el].spsr   = 0;
        cpu->el[el].elr    = 0;
        cpu->el[el].vbar   = 0;
        cpu->el[el].ttbr0  = 0;
        cpu->el[el].ttbr1  = 0;
        cpu->el[el].tcr    = 0;
        cpu->el[el].mair   = 0;
        cpu->el[el].sctlr  = 0;
    } 

    cpu->cycles = 0;
    cpu->halted = 0;
    cpu->exception_pending = 0;
    cpu->irq_line = 0;
    cpu->fiq_line = 0;
}

void cpu_dump(const CPU* cpu) {
    if (!cpu) return;

    printf("=== CPU State Dump ===\n");

    // General-purpose registers
    for (int i = 0; i < NUM_GP_REGS; ++i) {
        printf("X%-2d = 0x%016llx\n", i, (unsigned long long)cpu->x[i]);
    }

    // SP and PC
    printf(" SP  = 0x%016llx\n", (unsigned long long)cpu->sp);
    printf(" PC  = 0x%016llx\n", (unsigned long long)cpu->pc);

    // PSTATE flags
    printf("Flags: N=%d Z=%d C=%d V=%d  D=%d A=%d I=%d F=%d IL=%d SS=%d\n",
        cpu->pstate.N,
        cpu->pstate.Z,
        cpu->pstate.C,
        cpu->pstate.V,
        cpu->pstate.D,
        cpu->pstate.A,
        cpu->pstate.I,
        cpu->pstate.F,
        cpu->pstate.IL,
        cpu->pstate.SS
    );

    // Current exception level
    printf("EL    = %d\n", cpu->current_el);

    // Print per-EL system state (optional: only current EL)
    int el = cpu->current_el;
    printf("---- EL%d System State ----\n", el);
    printf(" SP_EL%d   = 0x%016llx\n", el, (unsigned long long)cpu->el[el].sp);
    printf(" SPSR_EL%d = 0x%016llx\n", el, (unsigned long long)cpu->el[el].spsr);
    printf(" ELR_EL%d  = 0x%016llx\n", el, (unsigned long long)cpu->el[el].elr);
    printf(" VBAR_EL%d = 0x%016llx\n", el, (unsigned long long)cpu->el[el].vbar);
    printf(" TTBR0_EL%d = 0x%016llx\n", el, (unsigned long long)cpu->el[el].ttbr0);
    printf(" TTBR1_EL%d = 0x%016llx\n", el, (unsigned long long)cpu->el[el].ttbr1);
    printf(" TCR_EL%d   = 0x%016llx\n", el, (unsigned long long)cpu->el[el].tcr);
    printf(" MAIR_EL%d  = 0x%016llx\n", el, (unsigned long long)cpu->el[el].mair);
    printf(" SCTLR_EL%d = 0x%016llx\n", el, (unsigned long long)cpu->el[el].sctlr);

    // Optional cycle count
    printf("Cycles: %llu\n", (unsigned long long)cpu->cycles);
    printf("Halted: %s\n", cpu->halted ? "yes" : "no");
}

void cpu_step(CPU *cpu) {
    // 1. Fetch
    uint32_t instr = memory_read32(cpu->pc);

    // 2. Decode + Execute
    if ((instr & 0xFFC00000) == OPCODE_MOVZ) {
        // MOVZ Xd, #imm
        uint8_t rd = (instr >> 0) & 0x1F;
        uint16_t imm16 = (instr >> 5) & 0xFFFF;
        cpu->x[rd] = imm16;
        cpu->pc += 4;
    }
    else if ((instr & 0xFF000000) == OPCODE_ADD_IMM) {
        // ADD Xd, Xn, #imm
        uint8_t rd = (instr >> 0) & 0x1F;
        uint8_t rn = (instr >> 5) & 0x1F;
        uint16_t imm12 = (instr >> 10) & 0xFFF;
        cpu->x[rd] = cpu->x[rn] + imm12;
        cpu->pc += 4;
    }
    else if (instr == OPCODE_HLT) {
        // HLT instruction — halt CPU
        cpu->halted = 1;
    }
    else {
        printf("Unknown instruction 0x%08X at PC=0x%016llX\n", instr, cpu->pc);
        cpu->halted = 1;
    }
}
