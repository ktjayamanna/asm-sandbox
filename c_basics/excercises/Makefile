# Makefile for Array Debugging Exercises
# Learn array addressing through hands-on debugging with GDB

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
DEBUG_CFLAGS = -Wall -Wextra -std=c99 -g -O0 -fno-omit-frame-pointer
TARGET = buggy_arrays
SOURCE = buggy_arrays.c

# Default target
all: $(TARGET)

# Compile the program
$(TARGET): $(SOURCE)
	$(CC) $(DEBUG_CFLAGS) -o $(TARGET) $(SOURCE)

# Run the debugging challenge
run: $(TARGET)
	@echo "🐛 ARRAY DEBUGGING CHALLENGE"
	@echo "============================="
	@echo "This program contains 6 intentional bugs!"
	@echo "Use 'make gdb' to start debugging."
	@echo "See README.md for investigation hints."
	@echo ""
	./$(TARGET)

# Start GDB debugging session
gdb: $(TARGET)
	@echo "🔍 STARTING GDB DEBUGGING SESSION"
	@echo "=================================="
	@echo "Quick start commands:"
	@echo "  (gdb) break main"
	@echo "  (gdb) run"
	@echo "  (gdb) break bug_array_bounds"
	@echo "  (gdb) continue"
	@echo "  (gdb) step"
	@echo ""
	@echo "See README.md for detailed investigation hints!"
	@echo ""
	gdb ./$(TARGET)

# Run with memory debugging (if valgrind is available)
valgrind: $(TARGET)
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "🔍 Running with Valgrind memory checker..."; \
		valgrind --tool=memcheck --leak-check=full --track-origins=yes ./$(TARGET); \
	else \
		echo "Valgrind not available, running normally..."; \
		./$(TARGET); \
	fi

# Clean up compiled files
clean:
	rm -f $(TARGET)

# Show assembly code (for advanced debugging)
disasm: $(TARGET)
	@if command -v objdump >/dev/null 2>&1; then \
		echo "🔍 Assembly code for main function:"; \
		objdump -d $(TARGET) | grep -A 30 "<main>:"; \
	else \
		echo "objdump not available"; \
	fi

# Show program size information
size: $(TARGET)
	@if command -v size >/dev/null 2>&1; then \
		echo "📊 Program size information:"; \
		size $(TARGET); \
	else \
		ls -la $(TARGET); \
	fi

# Help target
help:
	@echo "🐛 ARRAY DEBUGGING EXERCISES"
	@echo "============================="
	@echo "Learn array addressing by debugging real bugs!"
	@echo ""
	@echo "Available commands:"
	@echo "  make all      - Compile the debugging challenge"
	@echo "  make run      - Run the buggy program"
	@echo "  make gdb      - Start GDB debugging session ⭐"
	@echo "  make valgrind - Run with memory checker"
	@echo "  make clean    - Remove compiled files"
	@echo "  make disasm   - Show assembly code"
	@echo "  make size     - Show program size"
	@echo "  make help     - Show this help"
	@echo ""
	@echo "🚀 Start here: make gdb"
	@echo "📖 Read: README.md for investigation hints"

.PHONY: all run gdb valgrind clean disasm size help
