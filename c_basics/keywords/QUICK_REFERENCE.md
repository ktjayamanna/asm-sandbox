# C Keywords Quick Reference

## All 32 C Keywords at a Glance

### Data Types (9 keywords)
| Keyword | Purpose | Example |
|---------|---------|---------|
| `char` | Single character (8 bits) | `char letter = 'A';` |
| `int` | Standard integer (32 bits) | `int age = 25;` |
| `float` | Single precision decimal (32 bits) | `float price = 19.99f;` |
| `double` | Double precision decimal (64 bits) | `double pi = 3.14159;` |
| `short` | Short integer (16 bits) | `short year = 2024;` |
| `long` | Long integer (64 bits) | `long population = 8000000000L;` |
| `signed` | Can be negative (default) | `signed int temp = -10;` |
| `unsigned` | Only positive values | `unsigned int count = 100;` |
| `void` | No return type/empty params | `void print_hello(void);` |

### Storage Classes (4 keywords)
| Keyword | Purpose | Example |
|---------|---------|---------|
| `auto` | Automatic storage (default local) | `auto int x = 10;` |
| `extern` | External linkage declaration | `extern int global_var;` |
| `register` | CPU register hint | `register int i;` |
| `static` | Static storage/internal linkage | `static int counter = 0;` |

### Control Flow (13 keywords)
| Keyword | Purpose | Example |
|---------|---------|---------|
| `if` | Conditional execution | `if (x > 0) { ... }` |
| `else` | Alternative condition | `else { ... }` |
| `for` | Counting loop | `for (int i = 0; i < 10; i++)` |
| `while` | Condition-checked loop | `while (x > 0) { ... }` |
| `do` | Post-condition loop | `do { ... } while (x > 0);` |
| `break` | Exit loop/switch | `break;` |
| `continue` | Skip to next iteration | `continue;` |
| `switch` | Multi-way branch | `switch (value) { ... }` |
| `case` | Switch case label | `case 1: ...` |
| `default` | Default switch case | `default: ...` |
| `goto` | Unconditional jump | `goto label;` |
| `return` | Return from function | `return value;` |

### Advanced Types (6 keywords)
| Keyword | Purpose | Example |
|---------|---------|---------|
| `struct` | Structure definition | `struct Point { int x, y; };` |
| `union` | Union definition | `union Data { int i; float f; };` |
| `enum` | Enumeration | `enum Color { RED, GREEN, BLUE };` |
| `typedef` | Type alias | `typedef int Age;` |
| `const` | Read-only qualifier | `const int MAX = 100;` |
| `sizeof` | Size operator | `sizeof(int)` |
| `volatile` | Prevents optimization | `volatile int sensor;` |

## Memory Layout

```
Data Type Sizes (typical 64-bit system):
char:     1 byte  [0-255 unsigned, -128 to 127 signed]
short:    2 bytes [-32,768 to 32,767]
int:      4 bytes [-2,147,483,648 to 2,147,483,647]
long:     8 bytes [very large range]
float:    4 bytes [~7 decimal digits precision]
double:   8 bytes [~15 decimal digits precision]
```

## Common Patterns

### Variable Declaration Patterns
```c
// Basic types
int age = 25;
float price = 19.99f;
char grade = 'A';

// Modified types
unsigned int count = 100;
long long big_number = 1234567890LL;
const double PI = 3.14159;

// Arrays
int numbers[10];
char name[50];

// Pointers
int* ptr = &age;
const char* message = "Hello";
```

### Control Flow Patterns
```c
// Conditional
if (condition) {
    // code
} else if (other_condition) {
    // code
} else {
    // code
}

// Loops
for (int i = 0; i < n; i++) { /* code */ }
while (condition) { /* code */ }
do { /* code */ } while (condition);

// Switch
switch (value) {
    case 1: /* code */ break;
    case 2: /* code */ break;
    default: /* code */ break;
}
```

### Structure Patterns
```c
// Define structure
struct Student {
    char name[50];
    int age;
    float gpa;
};

// Use structure
struct Student s1 = {"Alice", 20, 3.8f};
printf("Name: %s\n", s1.name);

// Typedef for convenience
typedef struct Student Student_t;
Student_t s2 = {"Bob", 19, 3.5f};
```

## Compilation Commands

```bash
# Using the provided Makefile (recommended)
make all              # Compile all examples
make run-all          # Compile and run all examples
make data_types.exe   # Compile specific example
make clean            # Remove compiled files

# Manual compilation
gcc -o program.exe program.c

# With warnings and standards
gcc -Wall -Wextra -std=c99 -o program.exe program.c

# Debug version
gcc -g -Wall -Wextra -std=c99 -o program.exe program.c

# Optimized version
gcc -O2 -Wall -Wextra -std=c99 -o program.exe program.c
```

## Next Steps

1. Complete the practice exercise in `practice_exercise.c`
2. Experiment with combining different keywords
3. Try writing small programs using multiple concepts
4. Practice with pointers and dynamic memory allocation
5. Learn about preprocessor directives (#include, #define, etc.)
