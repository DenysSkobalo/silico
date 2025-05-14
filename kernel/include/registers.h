#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>
#include "cpu.h"

void get_registers(ARM_CPU* cpu, uint32_t* out);
uint32_t get_cpsr_value(ARM_CPU *cpu);

#endif
