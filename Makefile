.PHONY: run clean compile server graph all asm

BUILD_DIR = build
BINARY = main
SRC = kernel/cpu/src/main.c kernel/cpu/src/cpu.c 
INCLUDE_DIR = include
CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra -O2
AR = ar
ARFLAGS = rcs

# all: run
all: asm

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

graph:
	@gource --title "silico" --highlight-users -1280x720 -r 60 -s 0.5

asm:
	@as -arch arm64 -o somethings.o ./asm/arm64/somethings.s
	@ld -o somethings somethings.o -lSystem -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _start -arch arm64
	@./somethings
