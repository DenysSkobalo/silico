#include <stdio.h>
#include "registers.h"
#include "cpu.h"
#include "utils.h"

int main() {
    ARM_CPU cpu = init_cpu();
    print_cpu(&cpu);
    return 0;
}
