/*
 * storage_classes.c - Demonstrates C storage class keywords
 * Keywords covered: auto, extern, register, static
 */

#include <stdio.h>

// extern - declares a variable defined elsewhere
extern int global_counter;  // This would be defined in another file
                           // For this example, we'll define it below

// Define the extern variable (normally in another file)
int global_counter = 0;

// static - function with internal linkage (only visible in this file)
static void internal_function(void) {
    printf("This function is only visible within this file\n");
}

// Function demonstrating static local variables
void count_calls(void) {
    // static - local variable that retains its value between function calls
    static int call_count = 0;  // Initialized only once, not every call
    call_count++;
    printf("This function has been called %d times\n", call_count);
}

// Function demonstrating register keyword
int fast_calculation(int n) {
    // register - hint to compiler to store in CPU register for speed
    // Modern compilers usually ignore this and optimize automatically
    register int i;
    register int sum = 0;
    
    for (i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main(void) {
    printf("=== C Storage Classes Examples ===\n\n");

    // auto - automatic storage duration (default for local variables)
    // This keyword is rarely used explicitly since it's the default
    printf("auto keyword:\n");
    auto int local_var = 42;  // Same as: int local_var = 42;
    printf("Auto variable (local): %d\n", local_var);
    printf("(auto is the default for local variables)\n\n");

    // static - demonstrates persistent local variables
    printf("static keyword (local variables):\n");
    count_calls();  // call_count becomes 1
    count_calls();  // call_count becomes 2
    count_calls();  // call_count becomes 3
    printf("\n");

    // static - demonstrates internal linkage for functions
    printf("static keyword (functions):\n");
    internal_function();  // This function is only visible in this file
    printf("\n");

    // extern - demonstrates external linkage
    printf("extern keyword:\n");
    printf("Global counter (extern): %d\n", global_counter);
    global_counter = 100;
    printf("Modified global counter: %d\n", global_counter);
    printf("(extern allows access to variables defined elsewhere)\n\n");

    // register - demonstrates register hint
    printf("register keyword:\n");
    int result = fast_calculation(100);
    printf("Sum of 1 to 100 (using register hint): %d\n", result);
    printf("(register suggests storing variables in CPU registers)\n\n");

    // Demonstrate scope and lifetime differences
    printf("Scope and Lifetime Demo:\n");
    {
        auto int block_var = 10;  // auto - destroyed when block ends
        printf("Block variable: %d\n", block_var);
    }
    // block_var is no longer accessible here

    count_calls();  // static variable persists, becomes 4
    
    return 0;
}

/*
 * Key Points:
 * 
 * auto:
 * - Default storage class for local variables
 * - Automatic storage duration (created/destroyed with scope)
 * - Rarely written explicitly
 * 
 * extern:
 * - Declares a variable/function defined in another file
 * - Provides external linkage
 * - Allows sharing variables across multiple source files
 * 
 * register:
 * - Hint to compiler to store variable in CPU register
 * - May improve performance for frequently used variables
 * - Modern compilers often ignore this and optimize automatically
 * - Cannot take address of register variables
 * 
 * static:
 * - For local variables: retains value between function calls
 * - For global variables/functions: internal linkage (file scope only)
 * - Static local variables are initialized only once
 * - Useful for counters, caches, and private functions
 */
