 # TODO:
 
1. Instructions with flags ( ADDS, SUBS , ANDS, ANDIS )
    - implement update_flags() and call her in ALU

2. Branch instructions ( B, BL, BR, RET, CBZ, CBNZ )
    - implement execute_branch() and update `cpu->pc` according to `imm` or `Xn`

3. Memory instructions ( LDR, STR )
    - implement execute_mem() with access to memory_read64, memory_write64

4. Cycle accounting:
    - add `cpu->cycles += X;` in execute_* for diffrent instructions class

5. Shift / Rotate Instructions ( LSL, LSR, ASR, ROR)
    - implement decode_shift_fields() and add to execute_alu()
 
6. MOVK merge logic
    - `case OPCODE_MOVK:
    // mask = ~(0xFFFF << shift); replace 16-bit segment only
    cpu->x[rd] = (cpu->x[rd] & ~mask) | (imm << shift);`: use the correct mask to replace only part of the case

7. Support for NEG instruction:
    - NEG Xd, Xn == SUBS Xd, XZR, Xn - add branch in execute_alu()

8. General refactoring aand clean-up:
    - split decode() into partial per-class decode functions: `decode_rtype(), decode_imm(), decode_branch(), decode_mem()` and also execute(): `execute_alu(), execute_mem(), execute_branch(), execute_system()
`


