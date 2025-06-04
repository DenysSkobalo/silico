#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define RAM_SIZE (1024 * 1024)  // 1 MB

void memory_init();
uint32_t memory_read32(uint64_t addr);
void memory_write32(uint64_t addr, uint32_t value);

extern uint8_t ram[];

#endif
