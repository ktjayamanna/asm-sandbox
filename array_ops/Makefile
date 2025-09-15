# Simple Makefile for beginners

# To compile your program, just type: make
compile:
	riscv64-unknown-elf-gcc -nostdlib -march=rv32i -mabi=ilp32 -Wl,-Tarray_ops.ld array_ops.s -o array_ops.elf
	@echo "Done! Your program is now compiled into array_ops.elf"

# To see what your assembly code looks like after compiling
show:
	riscv64-unknown-elf-objdump -d array_ops.elf

startqemu: array_ops.elf
	# use qemu to run the elf file and wait for gdb to connect
	qemu-system-riscv32 -S -M virt -nographic -bios none -kernel array_ops.elf -gdb tcp::1234

connectgdb: array_ops.elf
	# Use GDB to attach to QEMU and step through the assembly code using the debug symbols in the ELF.
	gdb-multiarch array_ops.elf -ex 'target remote localhost:1234' -ex 'break _start' -ex 'continue' -q

# To clean up (delete the compiled file)
clean:
	rm -f *.elf *.bin