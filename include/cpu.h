#ifndef CPU_H
#define CPU_H

#include "registers.h"

typedef struct {
    // R0–R12: general purpose registers
	GPR R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12;

    // special purpose registers
    SPR SP;   // R13
    LR LR;   // R14
    PCR PC;   // R15

    // status registers
    CPSR CPSR;
} __attribute__((packed)) ARM_CPU;

ARM_CPU init_cpu();

#endif