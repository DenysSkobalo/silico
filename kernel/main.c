#include <string.h>
#include "include/memory.h"
#include "include/cpu.h"
// #include "../ipc/include/ipc.h"

int main() {
    // ipc_loop();

    memory_init();

    CPU cpu;
    cpu_init(&cpu);


    memory_write32(0x00, 0xD2800041);
    memory_write32(0x04, 0xD2800062);
    memory_write32(0x08, 0x8B020020);
    memory_write32(0x0C, 0x91001000);
    memory_write32(0x10, 0xD4400000);

    cpu.pc = 0x00;

   while(!cpu.halted) {
        cpu_tick(&cpu);
    }

    cpu_dump(&cpu);

    return 0;
}
