.PHONY: all run clean compile backend 

BUILD_DIR = build
BINARY = main

SRC = \
	kernel/src/cpu/cpu.c \
	kernel/src/memory/memory.c \
	kernel/src/core/core.c \
	kernel/src/core/alu.c \
	ipc/src/ipc.c \
	ipc/src/commands.c \
	kernel/main.c

INCLUDE_DIRS = -Ikernel/include -Iipc/include

CC = gcc
CFLAGS = $(INCLUDE_DIRS) -Wall -Wextra -O2

all: run

s: server
c: compile
r: run

// TODO: divide the compiling bin for cli and backend

run: compile
	@./$(BUILD_DIR)/$(BINARY)

compile:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(BINARY) $(SRC)
	@echo "Compilation complete."

server:
	@cd backend/ && go run ./cmd/server/main.go

clean:
	@rm -rf $(BUILD_DIR)
	@echo "Cleaned build files."
