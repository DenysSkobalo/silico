#include <stdio.h>
#include <stdint.h>
#include "../include/ipc.h"
#include "../include/commands.h"
#include "../../kernel/include/memory.h"
#include "../../kernel/include/cpu.h"

void cmd_init(CPU *cpu) {
    memory_init();
    cpu_init(cpu);
    printf("{\" status\": \"ok\"}\n");
    fflush(stdout);
}

void cmd_dump(CPU *cpu) {
    cpu_dump_json(cpu);
    fflush(stdout);
}
