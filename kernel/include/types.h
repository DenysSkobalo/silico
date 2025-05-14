#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

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

typedef uint32_t CPSR;

// special purpose registers
#define SPR(cpu) ((cpu)->R[13])
#define LR(cpu) ((cpu)->R[14])
#define PCR(cpu) ((cpu)->R[15])

#pragma pack(pop)
#endif