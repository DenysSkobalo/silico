.PHONY: all run clean compile server

BUILD_DIR = build
BINARY = main

SRC = \
	kernel/src/cpu/cpu.c \
	kernel/src/memory/memory.c \
	kernel/src/core/core.c \
	kernel/src/core/alu.c \
	ipc/src/ipc.c \
	ipc/src/commands.c \
	kernel/program.c \
	kernel/main.c

INCLUDE_DIRS = -Ikernel/include -Iipc/include

CC = gcc
CFLAGS = $(INCLUDE_DIRS) -Wall -Wextra -O2

ASM_SRC = asm/main.s
ASM_OBJ = asm/tmp.o
ASM_BIN = asm/tmp.bin
ASM_C   = kernel/program.c

ASM2C_BIN = asm2c

all: run

s: server
c: compile
r: run

run: compile
	@./$(BUILD_DIR)/$(BINARY)

compile: $(ASM_C)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(BINARY) $(SRC)
	@echo "Compilation complete."

server:
	@cd backend/ && go run ./cmd/server/main.go

clean:
	@rm -rf $(BUILD_DIR) $(ASM_OBJ) $(ASM_BIN) $(ASM_C)
	@echo "Cleaned build files."

# === Assembly → Binary → C header ===

$(ASM_C): $(ASM_SRC)
	@echo "Assembling $(ASM_SRC) into $(ASM_C)..."
	aarch64-unknown-linux-gnu-as -o $(ASM_OBJ) $(ASM_SRC)
	aarch64-unknown-linux-gnu-objcopy -O binary $(ASM_OBJ) $(ASM_BIN)
	@echo "#include <stdint.h>" > $(ASM_C)
	@echo "#include <stddef.h>" >> $(ASM_C)
	@echo "const uint8_t program_bytes[] = {" >> $(ASM_C)
	@xxd -i < $(ASM_BIN) | sed 's/unsigned.*{//' | sed 's/};//' >> $(ASM_C)
	@echo "};" >> $(ASM_C)
	@echo "const size_t program_size_bytes = sizeof(program_bytes);" >> $(ASM_C)
	@echo "Generated $(ASM_C)."
