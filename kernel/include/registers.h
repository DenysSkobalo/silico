#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

#define DEADBEEF_ADDRESS 0xDEADBEEF

// CPSR flag definitions
#define CPSR_FLAG_N   (1 << 31)
#define CPSR_FLAG_Z   (1 << 30)
#define CPSR_FLAG_C   (1 << 29)
#define CPSR_FLAG_V   (1 << 28)
#define CPSR_FLAG_Q   (1 << 27)
#define CPSR_FLAG_I   (1 << 7)
#define CPSR_FLAG_F   (1 << 6)
#define CPSR_FLAG_T   (1 << 5)
#define CPSR_MODE_MASK 0x1F

#pragma pack(push, 1)
typedef struct {
    uint32_t value;
} GPR; // General Purpose Register

typedef struct {
    uint32_t value;
} SPR; // Stack Pointer Register (R13)

typedef struct {
    uint32_t value;
} LR; // Link Register (R14) 

typedef struct {
    uint32_t value;
} PCR; // Program Counter (R15)

// Replace CPSR struct with uint32_t
typedef uint32_t CPSR;

#pragma pack(pop)
#endif
