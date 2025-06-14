// TODO: memory map

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "../../include/memory.h"

uint8_t ram[RAM_SIZE];

static int memory_is_valid_access(uint64_t addr, size_t size) {
    if (addr % size != 0) {
        fprintf(stderr, "Unaligned access at 0x%llx (size = %zu)\n", addr, size);
        return 0;
    }
    if (addr + size > RAM_SIZE) {
        fprintf(stderr, "Out-of-bounds access at 0x%llx (size = %zu)\n", addr, size);
        return 0;
    }
    return 1;
}

void memory_init() {
    memset(ram, 0, RAM_SIZE);
}

uint32_t memory_read32(uint64_t addr) {
    if (!memory_is_valid_access(addr, 4)) return 0xFFFFFFFF;
    return *(uint32_t*)&ram[addr];
}

void memory_write32(uint64_t addr, uint32_t value) {
    if (!memory_is_valid_access(addr, 4)) return;
    *(uint32_t*)&ram[addr] = value;
}
