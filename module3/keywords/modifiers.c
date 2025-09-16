/*
 * modifiers.c - Demonstrates C modifier keywords
 * Keywords covered: const, sizeof, volatile
 */

#include <stdio.h>

// const - read-only global variable
const double PI = 3.14159265359;
const char COMPANY_NAME[] = "Tech Corp";

// volatile - tells compiler variable can change unexpectedly
// (typically used for hardware registers or variables modified by interrupts)
volatile int sensor_reading = 0;

// Function with const parameters
void print_array(const int arr[], int size) {
    // arr[0] = 100;  // Error! Cannot modify const parameter
    
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function demonstrating const return value
const char* get_status(int code) {
    // Returns pointer to const string (string cannot be modified through this pointer)
    switch (code) {
        case 0: return "Success";
        case 1: return "Warning";
        case 2: return "Error";
        default: return "Unknown";
    }
}

int main(void) {
    printf("=== C Modifiers Examples ===\n\n");

    // const examples
    printf("=== Const Examples ===\n");
    
    // const variable - cannot be changed after initialization
    const int max_students = 30;
    const float tax_rate = 0.08f;
    
    printf("Max students: %d\n", max_students);
    printf("Tax rate: %.2f\n", tax_rate);
    printf("PI constant: %.5f\n", PI);
    printf("Company: %s\n", COMPANY_NAME);
    
    // max_students = 35;  // Error! Cannot modify const variable
    
    // const with pointers
    int value1 = 10, value2 = 20;
    
    // Pointer to const int (cannot change the value through pointer)
    const int* ptr_to_const = &value1;
    printf("Value through const pointer: %d\n", *ptr_to_const);
    // *ptr_to_const = 15;  // Error! Cannot modify value through const pointer
    ptr_to_const = &value2;  // OK! Can change what pointer points to
    printf("New value through const pointer: %d\n", *ptr_to_const);
    
    // Const pointer (cannot change what it points to)
    int* const const_ptr = &value1;
    *const_ptr = 25;  // OK! Can modify the value
    printf("Modified value through const pointer: %d\n", *const_ptr);
    // const_ptr = &value2;  // Error! Cannot change what const pointer points to
    
    // Const pointer to const int (cannot change pointer or value)
    const int* const const_ptr_to_const = &value1;
    printf("Value through const pointer to const: %d\n", *const_ptr_to_const);
    // *const_ptr_to_const = 30;  // Error! Cannot modify value
    // const_ptr_to_const = &value2;  // Error! Cannot change pointer
    
    printf("\n");

    // sizeof examples
    printf("=== Sizeof Examples ===\n");
    
    // sizeof - returns size in bytes of a type or variable
    printf("Size of basic types:\n");
    printf("sizeof(char): %zu bytes\n", sizeof(char));
    printf("sizeof(int): %zu bytes\n", sizeof(int));
    printf("sizeof(float): %zu bytes\n", sizeof(float));
    printf("sizeof(double): %zu bytes\n", sizeof(double));
    printf("sizeof(long): %zu bytes\n", sizeof(long));
    
    // sizeof with variables
    int numbers[10];
    char message[] = "Hello, World!";
    
    printf("\nSize of variables:\n");
    printf("sizeof(numbers): %zu bytes\n", sizeof(numbers));
    printf("sizeof(message): %zu bytes\n", sizeof(message));
    printf("sizeof(PI): %zu bytes\n", sizeof(PI));
    
    // sizeof for array length calculation
    int array_length = sizeof(numbers) / sizeof(numbers[0]);
    printf("Array length calculation: %d elements\n", array_length);
    
    // sizeof with structures
    struct Point {
        float x;
        float y;
    };
    
    printf("sizeof(struct Point): %zu bytes\n", sizeof(struct Point));
    
    printf("\n");

    // volatile examples
    printf("=== Volatile Examples ===\n");
    
    // volatile tells compiler the variable can change unexpectedly
    // (by hardware, interrupts, or other threads)
    printf("Sensor reading (volatile): %d\n", sensor_reading);
    
    // Simulate external change to volatile variable
    sensor_reading = 42;  // In real code, this might be changed by hardware
    printf("Updated sensor reading: %d\n", sensor_reading);
    
    // volatile prevents compiler optimizations that assume variable doesn't change
    volatile int counter = 0;
    for (int i = 0; i < 5; i++) {
        counter++;  // Compiler won't optimize this away due to volatile
        printf("Volatile counter: %d\n", counter);
    }
    
    printf("\n");

    // Practical examples
    printf("=== Practical Examples ===\n");
    
    // Using const with function parameters
    int test_array[] = {1, 2, 3, 4, 5};
    print_array(test_array, 5);
    
    // Using const return values
    const char* status = get_status(1);
    printf("Status message: %s\n", status);
    // status[0] = 'w';  // Error! Cannot modify const string
    
    // sizeof for dynamic memory allocation simulation
    int num_elements = 100;
    size_t memory_needed = num_elements * sizeof(int);
    printf("Memory needed for %d integers: %zu bytes\n", num_elements, memory_needed);

    return 0;
}

/*
 * Key Points:
 * 
 * const:
 * - Makes variables read-only after initialization
 * - Can be applied to variables, function parameters, and return values
 * - With pointers: "const int*" = pointer to const, "int* const" = const pointer
 * - Helps prevent accidental modifications and enables compiler optimizations
 * 
 * sizeof:
 * - Compile-time operator that returns size in bytes
 * - Works with types: sizeof(int), sizeof(double)
 * - Works with variables: sizeof(variable_name)
 * - Useful for array length calculation and memory allocation
 * - Returns size_t type (unsigned integer)
 * 
 * volatile:
 * - Tells compiler variable can change unexpectedly
 * - Prevents compiler optimizations that assume variable is constant
 * - Used for hardware registers, interrupt handlers, multi-threading
 * - Forces compiler to read from memory each time variable is accessed
 * - Less common in typical application programming
 */
