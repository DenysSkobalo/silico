.PHONY: all run clean compile asm

BUILD_DIR = build
BINARY = main

SRC = \
	kernel/main.c \
	kernel/src/cpu/cpu.c \
	kernel/src/memory/memory.c

INCLUDE_DIRS = -Iinclude/include
CC = gcc
CFLAGS = $(INCLUDE_DIRS) -Wall -Wextra -O2

all: run

run: compile
	@./$(BUILD_DIR)/$(BINARY)

clean:
	@rm -rf $(BUILD_DIR)
	@echo "🧹 Cleaned build files."

compile:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(BINARY) $(SRC)
	@echo "✅ Compilation complete."

asm:
	@mkdir -p $(BUILD_DIR)/asm
	@for file in $(SRC); do \
		$(CC) $(CFLAGS) -S $$file -o $(BUILD_DIR)/asm/`basename $$file .c`.s; \
	done
	@echo "🛠 Assembly code generated in $(BUILD_DIR)/asm/"
