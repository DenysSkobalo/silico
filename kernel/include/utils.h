#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include "cpu.h"

void print_binary(uint32_t value, int bits);
void print_cpu(const ARM_CPU* cpu);

#endif
