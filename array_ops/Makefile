# Simple Makefile for beginners

# To compile your program, just type: make
compile:
	riscv64-unknown-elf-gcc -nostdlib -march=rv32i -mabi=ilp32 -Wl,-Tarray_ops.ld array_ops.s -o array_ops.elf
	@echo "Done! Your program is now compiled into array_ops.elf"

# To see what your assembly code looks like after compiling
show:
	riscv64-unknown-elf-objdump -d array_ops.elf

# To clean up (delete the compiled file)
clean:
	rm -f *.elf *.bin
