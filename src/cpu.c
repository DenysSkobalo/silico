#include "cpu.h"

ARM_CPU init_cpu() {
    ARM_CPU cpu = {0};
    cpu.PC.value = 0x00000000;
    cpu.SP.value = 0xFFFFFFFC;
    cpu.CPSR.MODE = 0b10000; // User mode
    return cpu;
}