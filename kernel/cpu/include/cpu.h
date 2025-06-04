#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#define NUM_GP_REGS   31    // X0–X30
#define NUM_EL        4     // EL0, EL1, EL2, EL3

typedef struct {
    // General-purpose registers
    uint64_t x[NUM_GP_REGS];  // X0–X30
    uint64_t sp;              // Stack Pointer
    uint64_t pc;              // Program Counter

    // Processor status flags (PSTATE)
    struct {
        uint8_t N : 1;  // Negative
        uint8_t Z : 1;  // Zero
        uint8_t C : 1;  // Carry
        uint8_t V : 1;  // Overflow
        uint8_t D : 1;  // Debug mask
        uint8_t A : 1;  // SError mask
        uint8_t I : 1;  // IRQ mask
        uint8_t F : 1;  // FIQ mask
        uint8_t IL: 1;  // Illegal state
        uint8_t SS: 1;  // Software step
        uint8_t reserved : 6;
    } pstate;

    uint8_t current_el; // Exception Level (0–3)

    // Exception level context
    struct {
        uint64_t sp;
        uint64_t spsr;
        uint64_t elr;
        uint64_t vbar;
        uint64_t ttbr0;
        uint64_t ttbr1;
        uint64_t tcr;
        uint64_t mair;
        uint64_t sctlr;
    } el[NUM_EL];

    // Internal CPU state
    uint64_t cycles;
    uint8_t halted;
    uint8_t exception_pending;
    uint8_t irq_line;
    uint8_t fiq_line;

} CPU;

// === API ===
void cpu_init(CPU* cpu);           // Initialize CPU
void cpu_dump(const CPU* cpu);     // Print CPU state for debugging

#endif // CPU_H
