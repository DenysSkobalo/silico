#include <stdio.h>
#include "../../cpu/include/cpu.h"


int main() {
    CPU cpu;
    cpu_init(&cpu);
    cpu_dump(&cpu);

    return 0;
}
