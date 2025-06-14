#include <stdio.h>
#include <string.h>
#include "../../kernel/include/cpu.h"
// #include "../../kernel/include/memory.h" 
#include "../include/ipc.h" 
#include "../include/commands.h" 

static CPU cpu; 

void ipc_loop() {
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (strstr(buffer, "\"cmd\": \"init\"")) {
            cmd_init(&cpu);
        } else if (strstr(buffer, "\"cmd\": \"dump\"")) {
            cmd_dump(&cpu);
        } else {
            printf("{\"error\": \"unknown command\"}\n");
            fflush(stdout);
        }
    }
}

void cpu_dump_json(const CPU *cpu) {
    if (!cpu) return;

    printf("{");

    printf("\"x\": [");
    for (int i = 0; i < NUM_GP_REGS - 1; ++i)
        printf("%llu, ", (unsigned long long)cpu->x[i]);
    printf("%llu], ", (unsigned long long)cpu->x[NUM_GP_REGS - 1]);

    printf("\"sp\": %llu, ", (unsigned long long)cpu->sp);
    printf("\"pc\": %llu, ", (unsigned long long)cpu->pc);

    printf("\"pstate\": {");
    printf("\"N\": %u, \"Z\": %u, \"C\": %u, \"V\": %u, ", cpu->pstate.N, cpu->pstate.Z, cpu->pstate.C, cpu->pstate.V);
    printf("\"D\": %u, \"A\": %u, \"I\": %u, \"F\": %u, ", cpu->pstate.D, cpu->pstate.A, cpu->pstate.I, cpu->pstate.F);
    printf("\"IL\": %u, \"SS\": %u", cpu->pstate.IL, cpu->pstate.SS);
    printf("}, ");

    int el = cpu->current_el;
    printf("\"current_el\": %u, ", el);

    printf("\"el_state\": {");
    printf("\"sp\": %llu, ", (unsigned long long)cpu->el[el].sp);
    printf("\"spsr\": %llu, ", (unsigned long long)cpu->el[el].spsr);
    printf("\"elr\": %llu, ", (unsigned long long)cpu->el[el].elr);
    printf("\"vbar\": %llu, ", (unsigned long long)cpu->el[el].vbar);
    printf("\"ttbr0\": %llu, ", (unsigned long long)cpu->el[el].ttbr0);
    printf("\"ttbr1\": %llu, ", (unsigned long long)cpu->el[el].ttbr1);
    printf("\"tcr\": %llu, ", (unsigned long long)cpu->el[el].tcr);
    printf("\"mair\": %llu, ", (unsigned long long)cpu->el[el].mair);
    printf("\"sctlr\": %llu", (unsigned long long)cpu->el[el].sctlr);
    printf("}, ");

    printf("\"cycles\": %llu, ", (unsigned long long)cpu->cycles);
    printf("\"halted\": %s, ", cpu->halted ? "true" : "false");
    printf("\"exception_pending\": %u, ", cpu->exception_pending);
    printf("\"irq_line\": %u, ", cpu->irq_line);
    printf("\"fiq_line\": %u", cpu->fiq_line);

    printf("}\n");
    fflush(stdout);
}


