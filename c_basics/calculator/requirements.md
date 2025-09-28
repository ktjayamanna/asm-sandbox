# CLI Calculator Project Requirements

## What You'll Build
A simple command-line calculator that tests everything you've learned about C fundamentals.

## Mandatory Functional Requirements

### Feature 1: Type Size Display System
**Implementation**: Calculator must display memory usage information using `sizeof` operator and different data types.
**Required C Concepts**: `sizeof` operator, `char`, `int`, `long`, `float`, `double`
**Expected Behavior**:
```
=== Calculator Memory Information ===
char:   1 byte
int:    4 bytes
long:   8 bytes
float:  4 bytes
double: 8 bytes
```
**Why This Teaches**: Forces understanding of data type sizes and memory layout. The `sizeof` operator reveals how different types consume memory, essential for embedded systems where memory is limited.

### Feature 2: Operation Menu with Character Input
**Implementation**: Must use `char` variables to store single-character operation choices and `switch/case/default` for menu handling.
**Required C Concepts**: `char` data type, `switch`, `case`, `default`, input validation
**Expected Behavior**:
```
Choose operation:
a) Add
s) Subtract
m) Multiply
d) Divide
q) Quit
Enter choice: a
```
**Why This Teaches**: Demonstrates character handling and control flow. Using single characters instead of integers teaches ASCII values and efficient input processing.

### Feature 3: Calculation Counter with Static Variables
**Implementation**: Must use `static` variables inside functions to count total calculations performed across all function calls.
**Required C Concepts**: `static` storage class, function scope, persistent variables
**Expected Behavior**:
```
Calculation #1: 5 + 3 = 8
Calculation #2: 10 - 4 = 6
Calculation #3: 7 * 2 = 14
Total calculations performed: 3
```
**Why This Teaches**: Demonstrates how `static` variables maintain state between function calls, crucial for embedded state machines.

### Feature 4: Constant Mathematical Values
**Implementation**: Must define mathematical constants using `const` qualifier and use them in calculations.
**Required C Concepts**: `const` qualifier, mathematical constants, read-only data
**Expected Behavior**:
```
Circle area calculator:
Enter radius: 5.0
Area = π × r² = 3.14159 × 25.0 = 78.54
```
**Why This Teaches**: Shows how `const` prevents accidental modification of important values. Essential for embedded systems with hardware register definitions.

### Feature 5: Main Program Loop with Continue/Break
**Implementation**: Must use `while` loop for main program execution with `continue` for invalid input and `break` for exit condition.
**Required C Concepts**: `while` loop, `continue`, `break`, loop control
**Expected Behavior**:
```
Calculator running... (enter 'q' to quit)
Choice: x
Invalid choice! Please try again.
Choice: a
[performs addition]
Choice: q
Goodbye!
```
**Why This Teaches**: Demonstrates loop control flow and how `continue`/`break` alter program execution paths.

### Feature 6: Unsigned Integer Operations
**Implementation**: Must use `unsigned int` for operations that should never be negative (like absolute value calculations).
**Required C Concepts**: `unsigned` qualifier, type safety, value ranges
**Expected Behavior**:
```
Enter number for absolute value: -15
Absolute value: 15 (stored as unsigned int)
Maximum unsigned int value: 4294967295
```
**Why This Teaches**: Shows when unsigned types are appropriate and their different value ranges compared to signed types.

### Feature 7: Function Return Codes
**Implementation**: Must create separate functions for each operation that return error codes (0 = success, -1 = error) and use `return` statements.
**Required C Concepts**: Function definitions, `return` statement, error codes, function parameters
**Expected Behavior**:
```
Function add_numbers() returned: 0 (success)
Result: 15
Function divide_numbers() returned: -1 (error: division by zero)
```
**Why This Teaches**: Establishes pattern of error handling through return values, standard practice in embedded C programming.

### Feature 8: Multi-File Calculator Structure
**Implementation**: Must split calculator into exactly 3 files: `main.c` (menu system), `math_ops.c` (calculation functions), and `calculator.h` (function declarations). Must use `extern` declarations.
**Required C Concepts**: Multi-file compilation, `extern` keyword, function declarations vs definitions, header files
**Expected Behavior**:
```
$ gcc main.c math_ops.c -o calculator
$ ./calculator
Calculator loaded from multiple source files!
```
**Why This Teaches**: Shows how large C programs are organized. The `extern` keyword and header files are fundamental to modular programming in embedded systems.

### Feature 9: Operation Type System with Enums
**Implementation**: Must define operation types using `enum` and use `typedef` to create a custom type name. Must use this enum in switch statements.
**Required C Concepts**: `enum`, `typedef`, user-defined types, symbolic constants
**Expected Behavior**:
```
typedef enum { ADD_OP, SUB_OP, MUL_OP, DIV_OP, QUIT_OP } operation_t;
Current operation: ADD_OP (value: 0)
```
**Why This Teaches**: Enums create readable code and prevent magic numbers. Typedef creates meaningful type names. Both are essential for embedded systems with hardware state definitions.

### Feature 10: Calculation History with Structs
**Implementation**: Must create a `struct` to store calculation results (operands, operator, result) and maintain an array of these structs using `static` storage.
**Required C Concepts**: `struct`, arrays, `static` arrays, member access with `.` operator
**Expected Behavior**:
```
History Entry #1: 5.0 + 3.0 = 8.0
History Entry #2: 10.0 - 4.0 = 6.0
History Entry #3: 7.0 * 2.0 = 14.0
```
**Why This Teaches**: Structs group related data together. Static arrays persist between function calls. Essential for embedded systems that track sensor readings or system states.

### Feature 11: Input Retry Loop with For and Continue
**Implementation**: Must use `for` loop to limit input attempts (max 3 tries) and `continue` to restart input collection on invalid input.
**Required C Concepts**: `for` loops, `continue` statement, loop counters, input validation
**Expected Behavior**:
```
Enter a number (attempt 1/3): abc
Invalid input! Try again.
Enter a number (attempt 2/3): xyz
Invalid input! Try again.
Enter a number (attempt 3/3): 42
Success!
```
**Why This Teaches**: Shows controlled iteration and flow control. Prevents infinite loops from bad input. Critical for robust embedded systems that must handle sensor failures.

### Feature 12: Register Optimization Demonstration
**Implementation**: Must use `register` keyword for loop counter in a performance-critical calculation (like computing factorial) and time the difference.
**Required C Concepts**: `register` storage class, performance optimization, loop optimization
**Expected Behavior**:
```
Computing 20! with register optimization...
register int: 2432902008176640000 (computed in 0.001ms)
normal int: 2432902008176640000 (computed in 0.002ms)
```
**Why This Teaches**: Shows compiler optimization hints. While modern compilers often ignore `register`, understanding performance considerations is crucial for embedded systems.

### Feature 13: Memory Union Demonstration
**Implementation**: Must create a `union` that can store the same memory location as either an `int` or `float` to show memory overlap and type punning.
**Required C Concepts**: `union`, memory layout, type punning, memory efficiency
**Expected Behavior**:
```
Union memory demonstration:
Stored as int: 1078523331
Same memory as float: 3.140000
Union size: 4 bytes (same as largest member)
```
**Why This Teaches**: Unions save memory by overlapping data. Common in embedded systems for hardware register access where the same memory location can be interpreted as different data types.

### Feature 14: Volatile Flag for Graceful Shutdown
**Implementation**: Must use `volatile` global variable that can be modified by signal handler (Ctrl+C) to gracefully exit the calculator loop.
**Required C Concepts**: `volatile` qualifier, global variables, signal handling, compiler optimization prevention
**Expected Behavior**:
```
Calculator running... (Press Ctrl+C to exit gracefully)
^C
Shutdown signal received. Saving state...
Calculator exited cleanly.
```
**Why This Teaches**: `volatile` prevents compiler optimizations that assume variables don't change unexpectedly. Essential for embedded systems where hardware can modify memory locations.

### Feature 15: Assembly Code Generation and Analysis
**Implementation**: Must include a Makefile target that generates assembly code for key functions and requires documentation of the differences between optimized and unoptimized assembly.
**Required C Concepts**: Compilation process, assembly language, compiler optimizations, build systems
**Expected Behavior**:
```
$ make assembly
gcc -S -O0 math_ops.c -o math_ops_unopt.s
gcc -S -O2 math_ops.c -o math_ops_opt.s
Assembly files generated. Compare the optimization differences.
```
**Why This Teaches**: Understanding the assembly output helps you write more efficient C code. Critical for embedded systems where you need to understand the machine-level implications of your code.

### Feature 16: ASCII Character Analysis
**Implementation**: Must display ASCII values of operation characters and demonstrate character arithmetic. Must show how characters are stored as integers.
**Required C Concepts**: ASCII encoding, character literals, character arithmetic, type casting between `char` and `int`
**Expected Behavior**:
```
Operation characters and their ASCII values:
'+' = 43 (decimal) = 0x2B (hex) = 053 (octal)
'-' = 45 (decimal) = 0x2D (hex) = 055 (octal)
'*' = 42 (decimal) = 0x2A (hex) = 052 (octal)
'/' = 47 (decimal) = 0x2F (hex) = 057 (octal)

Character arithmetic: 'A' + 1 = 'B' (65 + 1 = 66)
```
**Why This Teaches**: Shows how characters are just small integers. Essential for embedded systems that process communication protocols or control character-based displays.

### Feature 17: Unicode Emoji Calculator Interface
**Implementation**: Must use UTF-8 encoded emoji characters to create a beautiful calculator interface. Must demonstrate multi-byte character handling and string literals.
**Required C Concepts**: UTF-8 encoding, multi-byte characters, string literals, locale handling
**Expected Behavior**:
```
🧮 ✨ EMOJI CALCULATOR ✨ 🧮

Choose your operation:
➕ a) Addition       (5 + 3 = 8)
➖ s) Subtraction    (10 - 4 = 6)
✖️  m) Multiplication (7 × 2 = 14)
➗ d) Division       (15 ÷ 3 = 5)
📊 h) Show History
🚪 q) Quit

Enter choice: a
🔢 Enter first number: 42
🔢 Enter second number: 13
✅ Result: 42 + 13 = 55
```
**Why This Teaches**: Modern embedded systems often need to display Unicode text on screens or send UTF-8 data over networks. Understanding multi-byte encoding is crucial.

### Feature 18: Character Encoding Converter
**Implementation**: Must create functions to convert between different character representations (ASCII decimal, hex, binary) and demonstrate how multi-byte UTF-8 characters are encoded.
**Required C Concepts**: Bitwise operations, character encoding, byte manipulation, hexadecimal representation
**Expected Behavior**:
```
🔤 Character Encoding Analysis 🔤

Enter a character: A
ASCII Analysis:
  Character: 'A'
  Decimal: 65
  Hexadecimal: 0x41
  Binary: 01000001

Enter an emoji: 🧮
UTF-8 Analysis:
  Character: 🧮
  Bytes: [0xF0, 0x9F, 0xA7, 0xAE] (4 bytes)
  Binary: 11110000 10011111 10100111 10101110
```
**Why This Teaches**: Embedded systems often need to parse communication protocols that mix ASCII and Unicode. Understanding byte-level encoding is essential for protocol implementation.

### Feature 19: Comprehensive Error Code System with Emoji
**Implementation**: Must define error codes using `#define` preprocessor directives and display errors with appropriate emoji indicators for visual feedback.
**Required C Concepts**: Preprocessor directives, `#define`, error handling patterns, function return values, Unicode string literals
**Expected Behavior**:
```
#define SUCCESS 0
#define ERROR_DIVISION_BY_ZERO -1
#define ERROR_OVERFLOW -2
#define ERROR_INVALID_INPUT -3

✅ Function returned: SUCCESS (0)
❌ Function returned: ERROR_DIVISION_BY_ZERO (-1)
⚠️  Function returned: ERROR_OVERFLOW (-2)
🚫 Function returned: ERROR_INVALID_INPUT (-3)
```
**Why This Teaches**: Combines systematic error handling with visual feedback. Shows how Unicode can improve user interfaces in embedded systems with displays.

## Complete Feature Implementation Checklist

### Core Data Types & Memory (Features 1, 13)
- [ ] Feature 1: Type size display using `sizeof`
- [ ] Feature 13: Union memory overlap demonstration

### Control Flow & Program Structure (Features 2, 5, 11)
- [ ] Feature 2: Character-based menu with `switch/case`
- [ ] Feature 5: Main loop with `while/continue/break`
- [ ] Feature 11: Input retry with `for` loop and `continue`

### Storage Classes & Persistence (Features 3, 10, 12, 14)
- [ ] Feature 3: Calculation counter with `static` variables
- [ ] Feature 10: History storage with `static` struct arrays
- [ ] Feature 12: Performance demo with `register` keyword
- [ ] Feature 14: Graceful shutdown with `volatile` flag

### Constants & Read-Only Data (Feature 4)
- [ ] Feature 4: Mathematical constants with `const` qualifier

### Integer Types (Feature 6)
- [ ] Feature 6: Unsigned integer operations and ranges

### Modular Programming (Features 7, 8, 9, 19)
- [ ] Feature 7: Function return codes and error handling
- [ ] Feature 8: Multi-file structure with `extern` declarations
- [ ] Feature 9: Type system with `enum` and `typedef`
- [ ] Feature 19: Error codes with `#define` and emoji feedback

### Character Encoding & Unicode (Features 16, 17, 18)
- [ ] Feature 16: ASCII character analysis and arithmetic
- [ ] Feature 17: Unicode emoji calculator interface
- [ ] Feature 18: Character encoding converter (ASCII/UTF-8)

### Assembly & Build System (Feature 15)
- [ ] Feature 15: Assembly generation and optimization analysis

## Project Structure
```
calculator/
├── main.c              # Features 2, 5, 11, 14, 17 (menu, loops, input, signals, emoji UI)
├── math_ops.c          # Features 3, 4, 7, 12 (operations, static counters, constants)
├── calculator.h        # Features 8, 9, 19 (extern, enums, error codes with emoji)
├── history.c           # Features 10, 13 (structs, unions)
├── encoding.c          # Features 16, 18 (ASCII analysis, UTF-8 conversion)
├── Makefile            # Feature 15 (assembly generation)
└── requirements.md     # This file
```

## Success Criteria
By implementing all 19 features, you will have mastered every fundamental C concept:
- **All data types**: `char`, `int`, `long`, `float`, `double`, `unsigned`
- **All qualifiers**: `const`, `volatile`, `static`, `extern`, `register`
- **All control flow**: `if/else`, `switch/case`, `while`, `for`, `break`, `continue`, `return`
- **All user types**: `struct`, `union`, `enum`, `typedef`
- **Character encoding**: ASCII values, UTF-8 multi-byte sequences, character arithmetic
- **All concepts**: functions, arrays, pointers, memory layout, compilation, assembly

## Bonus Learning Outcomes
- **Visual Programming**: Using Unicode to create beautiful, informative interfaces
- **Protocol Understanding**: How text encoding works in communication systems
- **Embedded Display Skills**: Character handling for LCD/OLED displays
- **International Support**: Multi-language text handling in embedded systems

This approach teaches C fundamentals AND character encoding through a beautiful, practical calculator! 🧮✨
