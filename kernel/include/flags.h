#ifndef FLAGS_H
#define FLAGS_H

// CPSR flag definitions
#define CPSR_FLAG_N   (1 << 31)
#define CPSR_FLAG_Z   (1 << 30)
#define CPSR_FLAG_C   (1 << 29)
#define CPSR_FLAG_V   (1 << 28)
#define CPSR_FLAG_Q   (1 << 27)
#define CPSR_FLAG_I   (1 << 7)
#define CPSR_FLAG_F   (1 << 6)
#define CPSR_FLAG_T   (1 << 5)
#define CPSR_MODE_MASK 0x1F

#endif