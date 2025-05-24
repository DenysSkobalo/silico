#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef enum {
    EL0 = 0,
    EL1 = 1,
    EL2 = 2,
    EL3 = 3,
} ExceptionLevel_t;

typedef struct {
    int N;
    int Z;
    int C;
    int V;
    ExceptionLevel_t EL;
    int I;
    int F;
    int D;
} PStateFlags_t;

// 64-bit 
typedef struct {
    uint64_t X[31]; // GPR
    uint64_t SP;
    uint64_t PC;
    PStateFlags_t PSTATE;   
} CPUState_t;

void init_cpu(CPUState_t *cpu, uint64_t reset_verctor);
void cpu_dump(const CPUState_t *cpu);

#endif
