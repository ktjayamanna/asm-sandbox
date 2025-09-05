welcome:
	@echo "Welcome to the Assembly & C Development Sandbox!"

machinecode: m.s m.ld
	# Create an ELF executable (main.elf) containing your assembly instructions plus debugging information.
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-Tm.ld m.s -o main.elf
	# Convert the ELF into a raw flat binary (main.bin) containing only the machine instructions (no ELF headers or debug info).
	riscv64-unknown-elf-objcopy -O binary main.elf main.bin

printmachinecode: machinecode
	# Print the binary file in hex format to see the instrcutions. Use https://luplab.gitlab.io/ to decode the instructions.
	xxd -e -c 4 -g 4 main.bin

startqemu: main.elf
	# use qemu to run the elf file and wait for gdb to connect
	qemu-system-riscv32 -S -M virt -nographic -bios none -kernel main.elf -gdb tcp::1234

connectgdb: main.elf
	# Use GDB to attach to QEMU and step through the assembly code using the debug symbols in the ELF.
	gdb-multiarch main.elf -ex 'target remote localhost:1234' -ex 'break _get_five' -ex 'continue' -q

clean: 
	# Clean up generated files
	@rm -f *.elf *.bin *.out