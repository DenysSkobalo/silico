#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

#define DEADBEEF_ADDRESS 0xDEADBEEF

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

typedef struct {
    uint32_t N : 1; // Negative flag
    uint32_t Z : 1; // Zero flag
    uint32_t C : 1; // Carry flag
    uint32_t V : 1; // Overflow flag
    uint32_t Q : 1; // Sticky overflow
    uint32_t _res1 : 3;
    uint32_t I : 1; // IRQ disable
    uint32_t F : 1; // FIQ disable
    uint32_t T : 1; // Thumb state
    uint32_t _res2 : 5;
    uint32_t MODE : 5; // Processor mode (User, FIQ, IRQ, Supervisor, etc.)
    uint32_t _res3 : 13;
} CPSR; 

#endif
