#include <stdio.h>
#include "../include/registers.h"
#include "../include/cpu.h"
#include "../include/utils.h"
#include <stddef.h>

int main() {
    ARM_CPU cpu = init_cpu();
    printf("ARMv7 or Cortex-M\n");
    print_cpu(&cpu);
    return 0;
}
