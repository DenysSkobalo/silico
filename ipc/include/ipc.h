#ifndef IPC_H
#define IPC_H

#include "../../kernel/include/cpu.h"

void ipc_loop(void);
void cpu_dump_json(const CPU *cpu);


#endif 
