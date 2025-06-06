# Silico

- Target ISA: ARMv8-A CPU (AArch64)

## Testing platform:
- OS: `macOS Darwin 23.6.0`
- Arch: `arm64` (Apple M1)

## Implementation Details
### CPU Logic
- 31 general-purpose 64-bit registers (X0-X30)
- Special registers SP, PC, PSTATE
- Execution cycle: fetch -> decode -> execute
- Control flags: halted, EL levels
### Memory Model
- RAM: flat 64KiB array
- Access: 32-bit words 

## References
- https://developer.arm.com/documentation/ddi0487/fc/
- https://www.qemu.org/
