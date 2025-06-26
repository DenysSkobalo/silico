#include <stdio.h>
#include <stdint.h>
#include "../../include/alu.h"
#include "../../include/core.h"
#include "../../include/cpu.h"

void execute_alu(CPU *cpu, DecodeInstr d) {
    uint64_t rn_val = (d.rn == 31) ? 0 : cpu->x[d.rn];
    uint64_t rm_val = (d.rm == 31) ? 0 : cpu->x[d.rm];

    switch (d.opcode) {
        // R-type arithmetic
        case OPCODE_ADD:
            cpu->x[d.rd] = rn_val + rm_val;
            break;

        case OPCODE_SUB:
            cpu->x[d.rd] = rn_val - rm_val;
            break;

        case OPCODE_MUL:
            cpu->x[d.rd] = rn_val * rm_val;
            break;

        // Logic ops (R-type)
        case OPCODE_AND:
            cpu->x[d.rd] = rn_val & rm_val;
            break;

        case OPCODE_ORR:
            cpu->x[d.rd] = rn_val | rm_val;
            break;

        case OPCODE_EOR:
            cpu->x[d.rd] = rn_val ^ rm_val;
            break;

        // Load constants
        case OPCODE_MOVZ:
            cpu->x[d.rd] = ((uint64_t)d.imm) << d.shift;
            break;

        case OPCODE_MOVK: {
            uint64_t mask = ~((uint64_t)IMM16_MASK << d.shift);
            cpu->x[d.rd] = (cpu->x[d.rd] & mask) | ((uint64_t)d.imm << d.shift);
            break;
        }

        case OPCODE_MOVN:
            cpu->x[d.rd] = ~(((uint64_t)d.imm) << d.shift);
            break;

        default:
            printf("Unimplemented ALU op: %d\n", d.opcode);
            break;
    }
}
