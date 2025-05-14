#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "types.h"

#pragma pack(push, 1)
typedef struct {
    // R0–R15: general and special purpose registers
    GPR R[16];
    // status registers
    CPSR CPSR;
} __attribute__((packed)) ARM_CPU;

ARM_CPU init_cpu();

#pragma pack(pop)
#endif