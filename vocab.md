# Computer Organization Vocabulary

## Memory Concepts
- **Offset**: Byte distance from a base memory address
- **Alignment**: Placing data at addresses divisible by specific values for efficient CPU access
- **Padding**: Extra bytes inserted by compiler to maintain alignment
- **Chunk**: Basic unit of memory accessed in single CPU operation
- **Word Size**: Natural data size CPU handles most efficiently (register size)

## CPU Architecture
- **x86_64**: 64-bit architecture with 8-byte word size
- **RISC-V**: RISC architecture with configurable word sizes
- **SIMD**: Single Instruction Multiple Data extensions for parallel processing
- **Cache Line**: Fundamental unit of cache memory management (typically 64 bytes)

## Memory Hierarchy
- **L1/L2/L3 Cache**: CPU memory levels with different sizes and speeds
- **RAM**: Main system memory
- **Page Size**: OS memory management unit (typically 4KB)

## Access Patterns
- **Aligned Access**: Memory operations at properly aligned addresses (fast)
- **Unaligned Access**: Memory operations at misaligned addresses (slow or crashing)
- **Atomic Operations**: Instructions that complete without interruption

## Compiler Role
- **ABI**: Application Binary Interface defining memory layout rules
- **Optimization**: Compiler decisions about padding and memory layout
- **Debug Symbols**: Optional metadata preserving type information

## Terminal Modes
- **Cooked Mode**: Line buffering, backspace works (default)
- **Raw Mode**: Character-at-a-time input, no line editing (i.e. nano)
- **VT100**: 1978 hardware terminal that modern terminals emulate.
- **Shell**: Program that interprets and executes commands (i.e. bash)
- **Buffering**: holding keystrokes in temporary memory
- **Character Echoing**: Typed characters are displayed on screen
- **Line Buffering**: Input is collected until Enter is pressed
- **Line Editing**: Backspace, delete word, etc. are handled automatically
