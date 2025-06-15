#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/core.h"
#include "../../include/cpu.h"
#include "../../include/memory.h"

static inline void decode_rtype_fields(DecodeInstr *d, uint32_t instr) {
    d->rd = (instr >> 0) & REG_MASK;
    d->rn = (instr >> 5) & REG_MASK;
    d->rm = (instr >> 16) & REG_MASK;
}

static inline void decode_imm12_fields(DecodeInstr *d, uint32_t instr) {
    d->rd = (instr >> 0) & REG_MASK;
    d->rn = (instr >> 5) & REG_MASK;
    d->imm = (instr >> 10) & IMM12_MASK;
}

static inline void decode_imm16_fields(DecodeInstr *d, uint32_t instr) {
    d->rd = (instr >> 0) & REG_MASK;
    d->imm = (instr >> 10) & IMM16_MASK;
}

Opcode extract_opcode(uint32_t instr) {
    // R-type arithmetic
    if ((instr & OPCODE_R_MASK) == OPCODE_ADD_VALUE)   return OPCODE_ADD;
    if ((instr & OPCODE_R_MASK) == OPCODE_ADDS_VALUE)  return OPCODE_ADDS;
    if ((instr & OPCODE_R_MASK) == OPCODE_SUB_VALUE)   return OPCODE_SUB;
    if ((instr & OPCODE_R_MASK) == OPCODE_SUBS_VALUE)  return OPCODE_SUBS;
    if ((instr & OPCODE_R_MASK) == OPCODE_MUL_VALUE)   return OPCODE_MUL;

    // Immediate arithmetic
    if ((instr & OPCODE_I_MASK) == OPCODE_ADDI_VALUE)  return OPCODE_ADDI;
    if ((instr & OPCODE_I_MASK) == OPCODE_SUBI_VALUE)  return OPCODE_SUBI;

    // Logical (R-type)
    if ((instr & OPCODE_R_MASK) == OPCODE_AND_VALUE)   return OPCODE_AND;
    if ((instr & OPCODE_R_MASK) == OPCODE_ORR_VALUE)   return OPCODE_ORR;
    if ((instr & OPCODE_R_MASK) == OPCODE_EOR_VALUE)   return OPCODE_EOR;
    if ((instr & OPCODE_R_MASK) == OPCODE_ANDS_VALUE)  return OPCODE_ANDS;

    // Logical (immediate)
    if ((instr & OPCODE_LOGIC_IMM_MASK) == OPCODE_ANDI_VALUE)  return OPCODE_ANDI;
    if ((instr & OPCODE_LOGIC_IMM_MASK) == OPCODE_ORRI_VALUE)  return OPCODE_ORRI;
    if ((instr & OPCODE_LOGIC_IMM_MASK) == OPCODE_EORI_VALUE)  return OPCODE_EORI;
    if ((instr & OPCODE_LOGIC_IMM_MASK) == OPCODE_ANDIS_VALUE) return OPCODE_ANDIS;

    // Load constants
    if ((instr & OPCODE_MOV_MASK) == OPCODE_MOVZ_VALUE) return OPCODE_MOVZ;
    if ((instr & OPCODE_MOV_MASK) == OPCODE_MOVK_VALUE) return OPCODE_MOVK;
    if ((instr & OPCODE_MOV_MASK) == OPCODE_MOVN_VALUE) return OPCODE_MOVN;

    // Branches
    if ((instr & OPCODE_BRANCH_MASK) == OPCODE_B_VALUE)   return OPCODE_UNKNOWN; // TODO
    if ((instr & OPCODE_BRANCH_MASK) == OPCODE_BL_VALUE)  return OPCODE_UNKNOWN; // TODO
    if ((instr & 0xFFFFFC1F) == OPCODE_RET_VALUE)         return OPCODE_UNKNOWN; // TODO

    // Compare & branch
    if ((instr & OPCODE_CB_MASK) == OPCODE_CBZ_VALUE)     return OPCODE_UNKNOWN; // TODO
    if ((instr & OPCODE_CB_MASK) == OPCODE_CBNZ_VALUE)    return OPCODE_UNKNOWN; // TODO

    // Memory access
    if ((instr & 0xFFC00000) == OPCODE_LDR_VALUE)         return OPCODE_UNKNOWN; // TODO
    if ((instr & 0xFFC00000) == OPCODE_STR_VALUE)         return OPCODE_UNKNOWN; // TODO

    // Exceptions
    if ((instr & OPCODE_EXCEPTION_MASK) == OPCODE_HLT_VALUE) return OPCODE_HLT;

    return OPCODE_UNKNOWN;
}

// Fetch: read an instruction from memory[PC]
uint32_t fetch(CPU *cpu) {
    if (cpu->pc % 4 != 0) {
        printf("Unaligned PC access: 0x%llx\n", cpu->pc);
        cpu->halted = 1;
        return 0;
    }

    if (cpu->pc >= RAM_SIZE) {
        printf("PC out of bounds: 0x%llx\n", cpu->pc);
        cpu->halted = 1;
        return 0;
    }

    return memory_read32(cpu->pc);
} 

// Decode: determine the type (ADD, SUB, MOV, LSR, B ...)
DecodeInstr decode(uint32_t instr) {
    DecodeInstr d = { .raw = instr};
    d.opcode = extract_opcode(instr);
    
    switch (d.opcode) {
        case OPCODE_ADD:
        case OPCODE_SUB:
        case OPCODE_AND:
        case OPCODE_ORR:
        case OPCODE_EOR:
        case OPCODE_ANDS:
            decode_rtype_fields(&d, instr);
            break;
        
        case OPCODE_ADDI: 
        case OPCODE_ORRI:
        case OPCODE_EORI:
        case OPCODE_ANDIS:
            decode_imm12_fields(&d, instr);
            break;

        case OPCODE_MOVZ:
        case OPCODE_MOVK:
        case OPCODE_MOVN:
            decode_imm16_fields(&d, instr);
            break;

        case OPCODE_HLT:
            break;

        default:
            printf("Unknown instruction: 0x%08X\n", instr);
            break;
    }
    
    return d;
} 

// Execute: change registers/flags/PC
void execute(CPU *cpu, DecodeInstr d) {
    switch (d.opcode) {
        case OPCODE_ADD:
            cpu->x[d.rd] = cpu->x[d.rn] + cpu->x[d.rm];
            break;

        case OPCODE_MOVZ: 
            cpu->x[d.rd] = d.imm;
            break;

        case OPCODE_ADDI:
            cpu->x[d.rd] = cpu->x[d.rn] + d.imm;
            break;

        case OPCODE_HLT:
            cpu->halted = 1;
            break;

        default:
            printf("Unimplemented instruction: opcode=%d\n", d.opcode);
            break;
    }
}

// void writeback(CPU *cpu, DecodeInstr *d, uint64_t result) {
// }

void update_pc(CPU *cpu, DecodeInstr d) {
    switch (d.opcode) {
        case OPCODE_HLT:
            break;

        default: 
            cpu->pc += 4;
            break;
    }
}

