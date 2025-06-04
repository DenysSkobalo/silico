#include <string.h>
#include <stdio.h>
#include "../../include/memory.h"

uint8_t ram[RAM_SIZE];

void memory_init() {
    memset(ram, 0, RAM_SIZE);
}

uint32_t memory_read32(uint64_t addr) {
    if (addr + 4 > RAM_SIZE) {
        printf("Memory read fault at 0x%llx\n", (unsigned long long)addr);
        return 0xFFFFFFFF;
    }
    return *(uint32_t*)&ram[addr];
}

void memory_write32(uint64_t addr, uint32_t value) {
    if (addr + 4 > RAM_SIZE) {
        printf("Memory write fault at 0x%llx\n", (unsigned long long)addr);
        return;
    }
    *(uint32_t*)&ram[addr] = value;
}
