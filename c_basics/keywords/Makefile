# Makefile for C Keywords Examples
# Usage: make [target]

CC = gcc
RISCV_CC = riscv64-unknown-elf-gcc
RISCV_FLAGS = -march=rv32i -mabi=ilp32
CFLAGS = -Wall -Wextra -std=c99
TARGETS = data_types.exe storage_classes.exe control_flow.exe advanced_types.exe modifiers.exe practice.exe

.PHONY: all clean help run-all

# Default target
all: $(TARGETS)

# Individual targets
data_types.exe: data_types.c
	$(CC) $(CFLAGS) -o $@ $<

storage_classes.exe: storage_classes.c
	$(CC) $(CFLAGS) -o $@ $<

control_flow.exe: control_flow.c
	$(CC) $(CFLAGS) -o $@ $<

advanced_types.exe: advanced_types.c
	$(CC) $(CFLAGS) -o $@ $<

modifiers.exe: modifiers.c
	$(CC) $(CFLAGS) -o $@ $<

practice.exe: practice_exercise.c
	$(CC) $(CFLAGS) -o $@ $<

# Run all examples
run-all: all
	@echo "=== Running Data Types Example ==="
	./data_types.exe
	@echo -e "\n=== Running Storage Classes Example ==="
	./storage_classes.exe
	@echo -e "\n=== Running Control Flow Example ==="
	./control_flow.exe
	@echo -e "\n=== Running Advanced Types Example ==="
	./advanced_types.exe
	@echo -e "\n=== Running Modifiers Example ==="
	./modifiers.exe

# playground file to try your own code.
run:
	gcc -o run.exe run.c
	./run.exe

# Generate assembly file for run.c (RISC-V 32-bit, unoptimized for learning)
# Creates temporary version without includes for assembly generation - shows all C operations
run.s: run.c
	@sed 's/#include.*//g; s/printf.*;//g' $< > run_temp.c
	@echo "void printf() {}" >> run_temp.c
	$(RISCV_CC) -S -O0 $(RISCV_FLAGS) -w -fno-builtin -ffreestanding -fno-dwarf2-cfi-asm -o $@ run_temp.c
	@rm -f run_temp.c

# Generate assembly file for run.c using regular gcc (x86_64, no debug info)
# This works with standard library calls like printf
run-x86.s: run.c
	$(CC) -S -O2 -fno-dwarf2-cfi-asm -o $@ $<

# Clean up compiled files
clean:
	rm -f $(TARGETS) *.s run.exe

# Help target
help:
	@echo "Available targets:"
	@echo "  all              - Compile all examples"
	@echo "  data_types.exe   - Compile data types example"
	@echo "  storage_classes.exe - Compile storage classes example"
	@echo "  control_flow.exe - Compile control flow example"
	@echo "  advanced_types.exe - Compile advanced types example"
	@echo "  modifiers.exe    - Compile modifiers example"
	@echo "  practice.exe     - Compile practice exercise"
	@echo "  run-all          - Compile and run all examples"
	@echo "  run.s            - Generate RISC-V 32-bit assembly for run.c (unoptimized, shows all ops)"
	@echo "  run-x86.s        - Generate x86_64 assembly for run.c (no debug info)"
	@echo "  clean            - Remove compiled files"
	@echo "  help             - Show this help message"
