.PHONY: run clean compile server all

BUILD_DIR = build
BINARY = main
SRC = kernel/src/main.c kernel/src/cpu.c kernel/src/utils.c
INCLUDE_DIR = include
CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra -O2
AR = ar
ARFLAGS = rcs

all: compile

run: clean compile
	@./$(BUILD_DIR)/$(BINARY)

clean:
	@rm -rf $(BUILD_DIR)
	@echo "Cleaned build files."

compile: $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(BINARY) $(SRC)
	@for file in $(SRC); do \
		$(CC) $(CFLAGS) -c $$file -o $(BUILD_DIR)/`basename $$file .c`.o; \
	done
	$(AR) $(ARFLAGS) $(BUILD_DIR)/libkernel.a $(BUILD_DIR)/*.o
	@echo "Compilation complete."
	@for file in $(SRC); do \
		$(CC) $(CFLAGS) -S $$file -o $(BUILD_DIR)/`basename $$file .c`.s; \
	done
	@echo "Generated assembly code."

server:
	@go run backend/cmd/server/main.go