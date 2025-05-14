.PHONY: run clean compile

BUILD_DIR = build
BINARY = main
SRC = src/main.c src/registers.c src/cpu.c src/utils.c

run: compile
	@./$(BUILD_DIR)/$(BINARY)

clean:
	@rm -rf $(BUILD_DIR)
	@echo "Cleaned build files."

compile: $(SRC)
	@mkdir -p $(BUILD_DIR)
	@gcc -Iinclude -o $(BUILD_DIR)/$(BINARY) $(SRC)
	@echo "Compilation complete."
	@for file in $(SRC); do \
		gcc -Iinclude -S $$file -o $(BUILD_DIR)/`basename $$file .c`.s; \
	done
	@echo "Generated assembly code."