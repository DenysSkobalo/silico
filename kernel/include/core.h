#ifndef CORE_H
#define CORE_H

#include "cpu.h"
#include <stdint.h>

#define OPCODE_ADD_VALUE  0x8B000000 // ADD 
#define OPCODE_SUB_VALUE  0xCB000000 // SUB
#define OPCODE_MOVZ_VALUE 0xD2800000 // MOVZ 
#define OPCODE_ADDI_VALUE 0x91000000 // ADDI 
#define OPCODE_HLT_VALUE  0xD4400000 // HLT (exception)

#define REG_MASK    0x1F // 5 bits: for getting number of register (0-31)
#define IMM12_MASK  0xFFF // 12 bits: for immediate value
#define IMM16_MASK  0xFFFF // 16 bits: for immediate value (0-65535)
#define OPCODE_Rformat_MASK 0xFFE00000 // mask of high 11 bits for determining an opecode of arichmetic instructions
#define OPCODE_HLT_MASK     0xFFFFFC00


typedef enum {
    OPCODE_UNKNOWN,
    OPCODE_ADD,
    OPCODE_MOVZ,
    OPCODE_SUB,
    OPCODE_ADDI,
    OPCODE_HLT
} Opcode;

typedef struct {
    uint32_t raw; // original instruction
    Opcode opcode; // determining of type
    uint16_t imm; // immediate (constant)
    uint8_t rd, rn, rm; // rd - writing result, rn - register source 1, rm - regsiter source 2
} DecodeInstr;

uint32_t fetch(CPU *cpu);
DecodeInstr decode(uint32_t instr);
void execute(CPU *cpu, DecodeInstr d);
void update_pc(CPU *cpu, DecodeInstr d);

#endif
