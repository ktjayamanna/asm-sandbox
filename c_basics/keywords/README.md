# C Keywords Examples

This directory contains simple, practical examples of all 32 C keywords, organized by category for easy learning.

## Directory Structure

- `data_types.c` - Basic data type keywords (char, int, float, double, etc.)
- `storage_classes.c` - Storage class specifiers (auto, extern, register, static)
- `control_flow.c` - Control flow keywords (if, else, for, while, etc.)
- `advanced_types.c` - Advanced type keywords (struct, union, enum, typedef)
- `modifiers.c` - Type modifiers and qualifiers (const, volatile, sizeof)
- `practice_exercise.c` - A skeleton file for you to practice with

## How to Compile and Run

### Using the Makefile (Recommended):
```bash
# Compile all examples
make all

# Run all examples
make run-all

# Compile individual examples
make data_types.exe
make storage_classes.exe
make control_flow.exe
make advanced_types.exe
make modifiers.exe
make practice.exe

# Run individual examples
./data_types.exe
./storage_classes.exe
./control_flow.exe
./advanced_types.exe
./modifiers.exe
./practice.exe

# Clean up compiled files
make clean

# Show help
make help
```

### Manual compilation:
```bash
gcc -o data_types.exe data_types.c
gcc -o storage_classes.exe storage_classes.c
gcc -o control_flow.exe control_flow.c
gcc -o advanced_types.exe advanced_types.c
gcc -o modifiers.exe modifiers.c
gcc -o practice.exe practice_exercise.c
```

## Keywords Covered

### Data Types (9 keywords)
- `char` - Character data type
- `int` - Integer data type
- `float` - Single precision floating point
- `double` - Double precision floating point
- `long` - Long integer modifier
- `short` - Short integer modifier
- `signed` - Signed number modifier
- `unsigned` - Unsigned number modifier
- `void` - No return type/empty parameter list

### Storage Classes (4 keywords)
- `auto` - Automatic storage duration (default for local variables)
- `extern` - External linkage declaration
- `register` - Hint to store in CPU register
- `static` - Static storage duration

### Control Flow (13 keywords)
- `if` - Conditional execution
- `else` - Alternative conditional execution
- `for` - Loop with initialization, condition, and increment
- `while` - Loop with condition check at start
- `do` - Loop with condition check at end
- `break` - Exit from loop or switch
- `continue` - Skip to next iteration of loop
- `switch` - Multi-way branch statement
- `case` - Label in switch statement
- `default` - Default case in switch statement
- `goto` - Unconditional jump
- `return` - Return from function

### Advanced Types (6 keywords)
- `struct` - Structure definition
- `union` - Union definition
- `enum` - Enumeration definition
- `typedef` - Type definition
- `const` - Constant qualifier
- `sizeof` - Size operator
- `volatile` - Volatile qualifier

## Learning Tips

1. Start with `data_types.c` to understand basic types
2. Move to `control_flow.c` for program logic
3. Study `storage_classes.c` for variable scope and lifetime
4. Explore `advanced_types.c` for complex data structures
5. Finish with `modifiers.c` for special qualifiers
6. Use `practice_exercise.c` to write your own examples

## Practice Exercise

Complete the skeleton code in `practice_exercise.c` to reinforce your understanding!
