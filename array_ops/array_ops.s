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

# ================================================================
# Core logic (just 8 instructions in the loop):
# beq - check if done
# slli - calculate byte offset
# add - calculate element address
# lw - load current value
# addi - add immediate to value
# sw - store value back
# addi - increment counter
# j - jump back to start
# ================================================================

# Shortest way to add 1 to each element in a zero array

.section .data
my_array:
    .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0    # Array already starts as zeros

.section .text
.global _start

_start:
    la x1, my_array     # x1 = array address
    addi x2, x0, 0      # x2 = counter (start at 0)
    addi x3, x0, 10     # x3 = array size (10)

loop:
    beq x2, x3, done    # if counter == 10, we're done
    
    slli x4, x2, 2      # x4 = counter * 4 (byte offset)
    add x5, x1, x4      # x5 = address of array[counter]
    lw x6, 0(x5)        # x6 = load current value
    addi x6, x6, 1      # x6 = x6 + 1
    sw x6, 0(x5)        # store x6 back to array[counter]
    
    addi x2, x2, 1      # counter++
    j loop              # repeat

done:
    j done              # infinite loop when finished
