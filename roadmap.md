# Embedded Systems

---

### **Phase 1: Foundation & The Machine Model**

*Goal: Set up your environment and build the crucial mental models of the computer system.*

**Module 1: The Setup & Mindset**

- **Sandbox Environment:** Set up a Linux VM or use WSL. Install the essential tools: `gcc`, `make`, `qemu-system-riscv32` (or another target), and `gdb`.
- **Basic C Program:** Write, compile, and run "Hello, World".
- **Mental Models to Internalize:**
    - **The System:** CPU, Memory, I/O devices.
    - **The CPU:** Fetch, Decode, Execute cycle. Registers (especially the Program Counter).
    - **The Memory:** A linear array of bytes. The concept of addresses.
- **From Text to Binary:** Understand the compilation pipeline: Preprocessor -> Compiler -> Assembler -> Linker.
- **Toolchain Tour:**
    - **QEMU:** Use it to emulate a simple RISC-V (rv32i) or ARM system.
    - **GDB:** Learn basic commands for debugging. Set up a GDB Dashboard for a better view.
    - **Demo:** Write a simple assembly program (.S), assemble it to binary, inspect it with `objdump`, and run it on QEMU, debugging with GDB.

---

### **Phase 2: Dwelling in Assembly**

*Goal: See the truth behind the C abstraction. This phase is critical for the rest of the journey.*

**Module 2: Assembly Language**

- **Anatomy of an Assembly Program:** Sections (`.text`, `.data`), directives, instructions, labels.
- **Writing & Debugging:** Write simple functions in assembly (e.g., add two numbers) and debug them step-by-step in GDB.
- **Decomposing C:** Write a simple C function (e.g., `int add(int a, int b) { return a + b; }`) and use `gcc -S` to generate the assembly. Analyze the correlation line-by-line.

---

### **Phase 3: C Fundamentals - Data & Keywords**

*Goal: Learn C's basic building blocks, understanding their direct translation to machine concepts.*

**Module 3: Data Types & Representation**

- **The Jump to C:** Understand how the CPU transitions from boot assembly to executing the `main()` function.
- **Introducing Keywords:** The vocabulary of the language.
- **Integers:** `char`, `short`, `int`, `long`, `long long`. Signed vs. Unsigned.
- **Storage:** How integers are stored in memory (2's complement).
- **Floating-Point:** `float` and `double`. Basic idea of IEEE 754 encoding.
- **Sizes & Locations:** Use `sizeof` and address-of (`&`) to explore variable sizes and memory addresses.
- **Qualifiers:**
    - `const`: Read-only data.
    - `volatile`: Preventing compiler optimizations (crucial for hardware registers).
    - `void`: The type of "nothing".
- **User-Defined Types:**
    - `typedef`: Creating type aliases.
    - `struct`: Grouping different data types together.
    - `union`: Overlapping data in memory (saving space vs. struct).
    - `enum`: Named integer constants.

**Module 4: Control Flow**

- **Branching:** `if`, `else`, `switch`, `case`, `default`.
- **Looping:** `do`, `while`, `for`.
- **Flow Alteration:** `continue`, `break`, `goto`, `return`.
- **Demos (Critical):** For each control flow keyword, write a small C example, compile to assembly (`gcc -S`), and analyze the resulting jump/branch instructions. This connects Phase 2 and Phase 3 directly.
- **Storage Classes:** (Understand their *meaning*, don't just memorize)
    - `auto`: Default for local variables (on the stack).
    - `register`: A hint to store a variable in a CPU register.
    - `static`: Persistence and file-scope.
    - `extern`: Declaring a variable/function defined elsewhere.

---

### **Phase 4: Core Concepts - Functions, Arrays, Pointers**

*Goal: Master the concepts that define C and give it its "raw power".*

**Module 5: Functions & Variables**

- **Definition vs. Declaration:** The critical difference.
- **Arithmetic Operations:** Pitfalls like integer overflow and floating-point imprecision.

**Project 1: CLI Calculator**

- **Goal:** Apply control flow, functions, and basic I/O.
- **Steps:** Use `printf`/`scanf` for I/O. Implement functions for `+`, , , `/`. Use a `switch` statement to choose the operation. Handle errors like division by zero.

**Module 6: Arrays, Strings, and Pointers**

- **The Trinity of C:** Understand how these three concepts are intertwined.
- **Arrays:** Definition, assignment, and the danger of out-of-bounds access.
- **Strings:** As character arrays (`char str[]`) vs. pointers to string literals (`char *str`).
- **Pointers:**
    - Concept: A variable that holds a memory address.
    - Syntax:  (dereference), `&` (address-of), pointer arithmetic.
    - **Demo:** Use GDB to print pointer values, dereference them, and watch how they change with arithmetic.
- **Detour - Endianness:** How multi-byte data is stored in memory (Big-endian vs. Little-endian).

**Project 2: Digital Audio Generator**

- **Goal:** Apply math, arrays, and file I/O.
- **Steps:**
    1. Understand sampling (e.g., 44.1 kHz).
    2. Generate an array of samples for a sine wave (e.g., 440 Hz).
    3. Write the raw sample data to a file (`.raw` or `.wav` header).
    4. Play the file with an audio player. This provides a tangible, audible result from your code!

---

### **Phase 5: Advanced Data Structures & Final Project**

*Goal: Synthesize all knowledge to model complex, real-world problems.*

**Module 7: User-Defined Data Types (Deep Dive)**

- **Revisiting `struct` and `union`:** Anatomy, memory layout, and padding.
- **Unions vs. Structs:** When to use a union to save memory (e.g., representing different sensor data types in a single packet).
- **Enums:** For code clarity and safety.

**Project 3: Embedded Sensor Management System**

- **Goal:** Model complex hardware data structures using nested structs and unions.
- **Specification Example:** Imagine a system that can read from different sensors (Temperature, GPS, Accelerometer). Each sensor sends data in a different format.
- **Steps:**
    1. Define a `struct` for each sensor's data packet.
    2. Create a master `union` that contains all these individual structs.
    3. Create a top-level `struct` that has the union *and* an `enum` field to identify which sensor type the data in the union belongs to (`packet_type`).
    4. Write functions that take this top-level struct, check the `packet_type`, and then interpret the data in the union accordingly.
- **This project perfectly demonstrates the "RAW power" of C mentioned in your outline.**

---