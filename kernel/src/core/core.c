#include <stdio.h>
#include <stdlib.h>
#include "../../include/core.h"
#include "../../include/cpu.h"
#include "../../include/memory.h"

Opcode extract_opcode(uint32_t instr) {
    if ((instr & OPCODE_Rformat_MASK) == OPCODE_ADD_VALUE) return OPCODE_ADD;
    if ((instr & OPCODE_Rformat_MASK) == OPCODE_SUB_VALUE) return OPCODE_SUB;
    if ((instr & 0xFFC00000) == OPCODE_MOVZ_VALUE) return OPCODE_MOVZ;
    if ((instr & 0xFF000000) == OPCODE_ADDI_VALUE) return OPCODE_ADDI;
    if ((instr & OPCODE_HLT_MASK) == OPCODE_HLT_VALUE) return OPCODE_HLT;

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
            d.rd = (instr >> 0) & REG_MASK;
            d.rn = (instr >> 5) & REG_MASK;
            d.rm = (instr >> 16) & REG_MASK;
            break;

        case OPCODE_MOVZ:
            d.rd = (instr >> 0) & REG_MASK;
            d.imm = (instr >> 5) & IMM16_MASK;
            break;
        
        case OPCODE_ADDI: 
            d.rd = (instr >> 0) & REG_MASK;
            d.rn = (instr >> 5) & REG_MASK;
            d.imm = (instr >> 10) & IMM12_MASK;
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

