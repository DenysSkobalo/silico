# VM Silico

## ARMv8-A 
- **Instruction Set**: AArch64 (A64 ISA)
- **ISA Width**: 32-bit instructions
- **Register File**: 31 * 64-bit GPR (General Purpose Registers) (`X0`-`X30`)
- **PC/SP**: 64-bit program counter & stack pointer
- **Exception Levels**: EL0-EL3 (currently `EL1` default)
- **System Registers**: SPSR_EL1, ELR_EL1, TTBR, TCR, SCTLR (mocked)
- **Memory Model**: flat array `ram[RAM_SIZE]` with bounds & alignmenet checks

## Testing platform:
- **OS**: `macOS Darwin 23.6.0`
- **Arch**: `arm64` (Apple M1)

## Implementation Details
### CPU Logic
- 31 general-purpose 64-bit registers (`X0`-`X30`)
- Special registers `SP`, `PC`, `PSTATE`
- Execution cycle: fetch -> decode -> execute -> update_pc 
- Control flags: halted, EL levels
### Memory Model
- **RAM**: flat memory array 1MB
- **Access granularity**: 32-bit words
- **Safety checks**: 
    - Alignmnet
    - Bounds

## References
- https://developer.arm.com/documentation/ddi0487/fc/
- https://developer.arm.com/-/media/Arm%20Developer%20Community/PDF/Learn%20the%20Architecture/Armv8-A%20Instruction%20Set%20Architecture.pdf?revision=ebf53406-04fd-4c67-a485-1b329febfb3e
- https://documentation-service.arm.com/static/649ae5b238511951cb799288
- https://en.wikipedia.org/wiki/ARM_architecture_family
- https://developer.arm.com/documentation/ddi0488/h/programmers-model/armv8-a-architecture-concepts
