#include <stdio.h>
#include "../../cpu/include/cpu.h"

#define RESET_VECTOR 0x0

int main() {
    CPUState_t cpu;
    init_cpu(&cpu, RESET_VECTOR);
    cpu_dump(&cpu);

    return 0;
}
