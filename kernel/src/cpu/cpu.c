// Stage 1: CPU struct -> cpu_init -> cpu_dump (DONE!)

// Stage 2 `Execution core`: fetch -> decode -> execute (DONE!)
// Stage 3 `ALU`
// Stage 4 `Threads Management`
// Stage 5 `Halt/Exception/Debug`

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/cpu.h"
#include "../../include/core.h"
// #include "../../include/memory.h"

#define RESET_VECTOR 0x0

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

void cpu_tick(CPU *cpu) {
    if (cpu->halted) return;

    uint32_t instr = fetch(cpu);
    printf("CPU tick: fetched: 0x%08X\n", instr);

    DecodeInstr d = decode(instr);
    printf("CPU tick: decoded: opcode=%d, rd=%d, rn=%d, rm=%d\n", d.opcode, d.rd, d.rn, d.rm);
    if (d.opcode == OPCODE_UNKNOWN) {
        printf("Unknown instruction: 0x%08X at PC=0x%llX\n", instr, (unsigned long long)cpu->pc);
    }

    execute(cpu, d);
    update_pc(cpu, d);
    printf("CPU tick: execute: halted = %d\n", cpu->halted);

}

