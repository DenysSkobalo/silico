#ifndef CORE_H
#define CORE_H

#include "cpu.h"
#include <stdint.h>

// Integer Arithmetic (R-type)
#define OPCODE_ADD_VALUE     0x8B000000  // ADD Xd, Xn, Xm
#define OPCODE_ADDS_VALUE    0xAB000000  // ADDS Xd, Xn, Xm (set flags)
#define OPCODE_SUB_VALUE     0xCB000000  // SUB Xd, Xn, Xm
#define OPCODE_SUBS_VALUE    0xEB000000  // SUBS Xd, Xn, Xm (set flags)
#define OPCODE_NEG_VALUE     OPCODE_SUBS_VALUE // NEG Xd, Xn == SUBS Xd, XZR, Xn
#define OPCODE_MUL_VALUE     0x9B007C00  // MUL Xd, Xn, Xm

// Multiply/accumulate
#define OPCODE_SMULL_VALUE   0x9B207C00  // SMULL Xd, Wn, Wm
#define OPCODE_UMULL_VALUE   0x9BA07C00  // UMULL Xd, Wn, Wm
#define OPCODE_SMLAL_VALUE   0x9B207C00  // SMLAL Xd, Wn, Wm
#define OPCODE_UMLAL_VALUE   0x9BA07C00  // UMLAL Xd, Wn, Wm

// Immediate Arithmetic (I-type)
#define OPCODE_ADDI_VALUE    0x91000000  // ADDI Xd, Xn, #imm12
#define OPCODE_SUBI_VALUE    0xD1000000  // SUBI Xd, Xn, #imm12


// Load Constants
#define OPCODE_MOVZ_VALUE    0xD2800000  // MOVZ Xd, #imm16
#define OPCODE_MOVK_VALUE    0xF2800000  // MOVK Xd, #imm16
#define OPCODE_MOVN_VALUE    0x92800000  // MOVN Xd, #imm16

// Logical Operations (R-type)
#define OPCODE_AND_VALUE     0x8A000000  // AND Xd, Xn, Xm
#define OPCODE_ORR_VALUE     0xAA000000  // ORR Xd, Xn, Xm
#define OPCODE_EOR_VALUE     0xCA000000  // EOR Xd, Xn, Xm
#define OPCODE_ANDS_VALUE    0xEA000000  // ANDS Xd, Xn, Xm

// Logical Immediate (I-type)
#define OPCODE_ANDI_VALUE    0x12000000  // AND (immediate)
#define OPCODE_ORRI_VALUE    0x32000000  // ORR (immediate)
#define OPCODE_EORI_VALUE    0x52000000  // EOR (immediate)
#define OPCODE_ANDIS_VALUE   0x72000000  // ANDS (immediate)

// Branch Instructions
#define OPCODE_B_VALUE       0x14000000  // Unconditional branch
#define OPCODE_BL_VALUE      0x94000000  // Branch with link
#define OPCODE_RET_VALUE     0xD65F0000  // Return
#define OPCODE_BR_VALUE      0xD61F0000  // Branch to register
#define OPCODE_CBZ_VALUE     0x34000000  // Compare and branch on zero
#define OPCODE_CBNZ_VALUE    0x35000000  // Compare and branch on non-zero

// Exception/Trap
#define OPCODE_HLT_VALUE     0xD4400000  // Halt

// Memory Access
#define OPCODE_LDR_VALUE     0xF9400000  // Load register (unsigned offset)
#define OPCODE_STR_VALUE     0xF9000000  // Store register (unsigned offset)

// Shift/Rotate (R-type or bitfield)
#define OPCODE_LSL_VALUE     0xD3400000
#define OPCODE_LSR_VALUE     0xD3400000
#define OPCODE_ASR_VALUE     0xD3400000
#define OPCODE_ROR_VALUE     0xD3400000  // all use shift mask

// Instruction Class Masks
#define OPCODE_R_MASK            0xFFE00000  // R-type
#define OPCODE_I_MASK            0xFF000000  // I-type
#define OPCODE_BRANCH_MASK       0xFC000000
#define OPCODE_CB_MASK           0xFF000000
#define OPCODE_EXCEPTION_MASK    0xFFFFFC00
#define OPCODE_LOGIC_IMM_MASK    0xFF800000

#define OPCODE_MOV_WIDE_MASK     0xFF800000
#define OPCODE_LS_MASK           0xFFC00000
#define OPCODE_LDUR_MASK         0xF8400000
#define OPCODE_STUR_MASK         0xF8000000

// Decode Helpers
#define REG_MASK    0x1F      // 5 bits: register
#define IMM12_MASK  0xFFF     // 12-bit immediate
#define IMM16_MASK  0xFFFF    // 16-bit immediate

typedef enum {
    OPCODE_UNKNOWN,
    OPCODE_ADD, OPCODE_ADDI,
    OPCODE_ADDS,
    OPCODE_SUB, OPCODE_SUBI,
    OPCODE_SUBS,
    OPCODE_NEG,
    OPCODE_MUL,
    OPCODE_SMULL,
    OPCODE_UMULL,
    OPCODE_SMLAL,
    OPCODE_UMLAL,
    OPCODE_MOVZ,
    OPCODE_MOVK,
    OPCODE_MOVN,
    OPCODE_AND, OPCODE_ANDI,
    OPCODE_ORR, OPCODE_ORRI,
    OPCODE_EOR, OPCODE_EORI,
    OPCODE_ANDS, OPCODE_ANDIS,
    OPCODE_B,
    OPCODE_BL,
    OPCODE_BR,
    OPCODE_RET,
    OPCODE_CBZ,
    OPCODE_CBNZ,
    OPCODE_LDR,
    OPCODE_STR,
    OPCODE_HLT
} Opcode;

typedef struct {
    uint32_t raw;           // Full 32-bit raw instruction
    Opcode opcode;          // Decoded type
    uint16_t imm;           // Immediate (if present)
    uint8_t rd, rn, rm;     // Registers: destination, operand1, operand2
} DecodeInstr;

static inline void decode_rtype_fields(DecodeInstr *d, uint32_t instr);
static inline void decode_imm12_fields(DecodeInstr *d, uint32_t instr);
static inline void decode_imm16_fields(DecodeInstr *d, uint32_t instr);

uint32_t fetch(CPU *cpu);
DecodeInstr decode(uint32_t instr);
void execute(CPU *cpu, DecodeInstr d);
void update_pc(CPU *cpu, DecodeInstr d);

#endif

// TODO:
// - Implement decoding for: B, BL, BR, RET, CBZ, CBNZ
// - Add shift instructions (LSL, LSR, ASR, ROR)
// - Support flags update for ADDS, SUBS, ANDS, ANDIS
