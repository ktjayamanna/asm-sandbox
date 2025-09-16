# Makefile for C Keywords Examples
# Usage: make [target]

CC = gcc
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

# Clean up compiled files
clean:
	rm -f $(TARGETS)

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
	@echo "  clean            - Remove compiled files"
	@echo "  help             - Show this help message"
