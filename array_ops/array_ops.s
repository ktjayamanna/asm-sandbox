# Simple array program: make 10 numbers, set them to 0, then add 1 to each

# Register Roles
# x1 - Array Base Address

# Holds the starting memory address of my_array
# Set once with la x1, my_array and never changes
# Think of it as a "pointer to the array"
# x2 - Loop Counter

# Tracks which array element we're currently processing (0, 1, 2... 9)
# Gets incremented with addi x2, x2, 1 each loop iteration
# Reset to 0 when starting the second loop
# x3 - Loop Limit

# Holds the value 10 (array size)
# Used in beq x2, x3, done to check if we've processed all elements
# Constant throughout the program
# x4 - Byte Offset

# Calculated as counter × 4 using slli x4, x2, 2
# Tells us how many bytes from the start of the array to find element[counter]
# Changes each iteration: 0, 4, 8, 12, 16...
# x5 - Element Address

# Calculated as base_address + offset using add x5, x1, x4
# Points to the exact memory location of the current array element
# Used in lw/sw instructions to access that specific element

# This is where we put our data (the array)
#.section is an assembler directive that tells the assembler which section of memory to place the following code/data into.
.section .data                              # Directive: .section <section_name>
my_array:                                   # Label: <label_name>:
    .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0     # Directive: .word <value1>, <value2>, ...

# This is where we put our code
.section .text                              # Directive: .section <section_name>
.global _start                              # Directive: .global <symbol_name>

_start:                                     # Label: <label_name>:
    # Step 1: Set up what we need
    la x1, my_array                         # Instruction: la <dest_reg>, <label>, x1 keeps the starting address of my_array.
    addi x2, x0, 0                          # Instruction: addi <dest_reg>, <src_reg>, <immediate>, current counter value.
    addi x3, x0, 10                         # Load 10 ONCE here, not in every loop!

# Step 2: Set all array elements to 0 (even though they already are 0)
zero_loop:                                  # Label: <label_name>:
    # Are we done? (counter == 10?)
    beq x2, x3, add_loop_start              # Instruction: beq <reg1>, <reg2>, <label>

    # Put 0 into array[counter]
    slli x4, x2, 2                          # Instruction: slli <dest_reg>, <src_reg>, <shift_amount>, since risc v does not have multipication, we use shift left logical instruction to multiply by 4.
    add x5, x1, x4                          # Instruction: add <dest_reg>, <src_reg1>, <src_reg2>
    sw x0, 0(x5)                            # Instruction: sw <src_reg>, <offset>(<base_reg>), add 0 immediate val to the address of x5 and store a zero value in that location.

    # Move to next element
    addi x2, x2, 1                          # Instruction: addi <dest_reg>, <src_reg>, <immediate>
    j zero_loop                             # Instruction: j <label>

# Step 3: Reset the counter back to zero.
add_loop_start:                             # Label: <label_name>:
    addi x2, x0, 0                          # Instruction: addi <dest_reg>, <src_reg>, <immediate>

add_loop:                                   # Label: <label_name>:
    # Are we done? (counter == 10?)
    beq x2, x3, done                        # x3 still has 10 from before!

    # Get array[counter], add 1, put it back
    slli x4, x2, 2                          # Instruction: slli <dest_reg>, <src_reg>, <shift_amount>
    add x5, x1, x4                          # Instruction: add <dest_reg>, <src_reg1>, <src_reg2>
    lw x6, 0(x5)                            # Instruction: lw <dest_reg>, <offset>(<base_reg>)
    addi x6, x6, 1                          # Instruction: addi <dest_reg>, <src_reg>, <immediate>
    sw x6, 0(x5)                            # Instruction: sw <src_reg>, <offset>(<base_reg>)

    # Move to next element
    addi x2, x2, 1                          # Instruction: addi <dest_reg>, <src_reg>, <immediate>
    j add_loop                              # Instruction: j <label>

# Step 4: We're done, just loop forever
done:                                       # Label: <label_name>:
    j done                                  # Instruction: j <label>
