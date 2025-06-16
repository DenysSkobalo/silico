#include <stdio.h>
#include <stdint.h>
#include "../../include/alu.h"
#include "../../include/core.h"
#include "../../include/cpu.h"

void execute_alu(CPU *cpu, DecodeInstr d) {
    switch (d.opcode) {
        // R-type arithmetic
        case OPCODE_ADD:
            cpu->x[d.rd] = cpu->x[d.rn] + cpu->x[d.rm];
            break;

        case OPCODE_SUB:
            cpu->x[d.rd] = cpu->x[d.rn] - cpu->x[d.rm];
            break;

        case OPCODE_MUL:
            cpu->x[d.rd] = cpu->x[d.rn] * cpu->x[d.rm];
            break;

        // I-type arithmetic
        case OPCODE_ADDI:
            cpu->x[d.rd] = cpu->x[d.rn] + d.imm;
            break;

        case OPCODE_SUBI:
            cpu->x[d.rd] = cpu->x[d.rn] - d.imm;
            break;

        // Logic ops
        case OPCODE_AND:
            cpu->x[d.rd] = cpu->x[d.rn] & cpu->x[d.rm];
            break;

        case OPCODE_ORR:
            cpu->x[d.rd] = cpu->x[d.rn] | cpu->x[d.rm];
            break;

        case OPCODE_EOR:
            cpu->x[d.rd] = cpu->x[d.rn] ^ cpu->x[d.rm];
            break;

        // Immediate logic
        case OPCODE_ANDI:
            cpu->x[d.rd] = cpu->x[d.rn] & d.imm;
            break;

         case OPCODE_ORRI:
            cpu->x[d.rd] = cpu->x[d.rn] | d.imm;
            break;

        case OPCODE_EORI:
            cpu->x[d.rd] = cpu->x[d.rn] ^ d.imm;
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
