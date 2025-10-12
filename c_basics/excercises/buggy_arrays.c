#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * CHALLENGE 1: Array Bounds
 *
 * EXPECTED BEHAVIOR:
 * - Calculate the average of exactly 5 test scores
 * - Should only access scores[0] through scores[4]
 * - Should print each valid score being added
 * - Should calculate correct total and average
 *
 * INVESTIGATION HINTS:
 * - Use GDB to examine the scores array memory layout
 * - Check what happens at each array index
 * - Look at the loop condition carefully
 * - What memory is being accessed beyond the array?
 */
void bug_array_bounds() {
    printf("\n=== CHALLENGE 1: Array Bounds ===\n");
    int scores[5] = {85, 92, 78, 96, 88};
    int total = 0;
    int count = 0;

    printf("Calculating average of 5 test scores...\n");
    printf("Expected total should be: 85+92+78+96+88 = 439\n");
    printf("Expected average should be: 439/5 = 87.80\n");
    printf("Expected to process: 5 elements\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Adding score[%d] = %d\n", i, scores[i]);
        total += scores[i];
        count++;
    }

    printf("\nRESULTS:\n");
    printf("Expected elements: 5\n");
    printf("Actually processed: %d elements\n", count, (count == 5) ? "✓" : "❌");
    printf("Expected total: 439\n");
    printf("Actual total: %d %s\n", total, (total == 439) ? "✓" : "❌");
    printf("Expected average: 87.80\n");
    printf("Actual average: %.2f %s\n", total / 5.0, (total / 5.0 == 87.80) ? "✓" : "❌");
    printf("\n🚨 PROBLEM: Processing %d elements instead of 5!\n", count);
}

/*
 * CHALLENGE 2: 2D Array Access
 *
 * EXPECTED BEHAVIOR:
 * - Access element at row 1, column 2 of a 3x4 matrix
 * - Should return the value 7 (matrix[1][2])
 * - Manual pointer arithmetic should match array indexing
 *
 * MATRIX LAYOUT:
 * Row 0: [1, 2, 3, 4]
 * Row 1: [5, 6, 7, 8]  <- We want element at position [1][2] = 7
 * Row 2: [9, 10, 11, 12]
 *
 * INVESTIGATION HINTS:
 * - How are 2D arrays stored in memory? (row-major order)
 * - What's the correct formula for 2D array element address?
 * - Use GDB to examine the entire matrix memory layout
 * - Compare the calculated pointer with the actual element address
 */
void bug_2d_array_access() {
    printf("\n=== CHALLENGE 2: 2D Array Access ===\n");
    int matrix[3][4] = {
        {1, 2,  3,  4},
        {5, 6,  7,  8},
        {9, 10, 11, 12}
    };

    printf("Matrix layout:\n");
    printf("Row 0: [1, 2, 3, 4]\n");
    printf("Row 1: [5, 6, 7, 8]  <- We want matrix[1][2] = 7\n");
    printf("Row 2: [9, 10, 11, 12]\n\n");

    printf("Trying to access matrix[1][2] using pointer arithmetic...\n");

    int* calculated_ptr = (int*)matrix + 1 + 2;
    int calculated_result = *calculated_ptr;
    int correct_result = matrix[1][2];

    printf("RESULTS:\n");
    printf("Expected value: 7\n");
    printf("Pointer arithmetic result: %d %s\n",
           calculated_result, (calculated_result == 7) ? "✓" : "❌");
    printf("Direct array access result: %d ✓\n", correct_result);

    if (calculated_result != correct_result) {
        printf("\n🚨 PROBLEM: Pointer arithmetic gives %d but should be %d!\n",
               calculated_result, correct_result);
        printf("The pointer arithmetic formula is wrong!\n");
    }
}

/*
 * CHALLENGE 3: String Array Access
 *
 * EXPECTED BEHAVIOR:
 * - Print three names: "Alice", "Bob", "Charlie"
 * - Each name should be printed clearly and correctly
 * - No garbage characters or crashes
 *
 * ARRAY SETUP:
 * - char names[3][10] creates a 2D character array
 * - Each row can hold up to 10 characters (including null terminator)
 * - Memory layout: [Alice\0\0\0\0\0Bob\0\0\0\0\0\0\0Charlie\0\0\0]
 *
 * INVESTIGATION HINTS:
 * - What's the difference between char[3][10] and char*[3]?
 * - How is the 2D char array stored in memory?
 * - What happens when you cast a 2D array to char**?
 * - Use GDB to examine the memory layout and pointer values
 */
void bug_string_arrays() {
    printf("\n=== CHALLENGE 3: String Array Access ===\n");
    char names[3][10] = {"Alice", "Bob", "Charlie"};

    printf("Expected output:\n");
    printf("Name 0: Alice\n");
    printf("Name 1: Bob\n");
    printf("Name 2: Charlie\n\n");

    printf("Actual output:\n");
    char** name_ptrs = (char**)names;

    for (int i = 0; i < 3; i++) {
        printf("Name %d: %s\n", i, name_ptrs[i]);
    }
}

/*
 * CHALLENGE 4: Buffer Overflow
 *
 * EXPECTED BEHAVIOR:
 * - Safely copy a string from source to destination
 * - Should not corrupt memory beyond the destination buffer
 * - Should handle cases where source is larger than destination
 *
 * THE SITUATION:
 * - Source string: 55+ characters
 * - Destination buffer: only 20 characters
 * - Current code attempts to copy without checking bounds
 *
 * INVESTIGATION HINTS:
 * - What happens when you copy more data than the buffer can hold?
 * - Use GDB to examine memory before and after the copy
 * - Look at memory addresses around the dest buffer
 * - What gets overwritten when the buffer overflows?
 * - How can you detect/prevent this type of error?
 */
void bug_buffer_overflow() {
    printf("\n=== CHALLENGE 4: Buffer Overflow ===\n");
    char source[] = "This string is way too long for the destination buffer!";
    char dest[20];
    char canary[] = "CANARY";  // This will get overwritten!

    printf("Source string: \"%s\"\n", source);
    printf("Source length: %zu characters\n", strlen(source));
    printf("Destination buffer size: %zu characters\n", sizeof(dest));
    printf("Will source fit? %s\n",
           (strlen(source) < sizeof(dest)) ? "YES ✓" : "NO ❌");
    printf("Canary value before copy: \"%s\"\n\n", canary);

    printf("Attempting to copy...\n");
    strcpy(dest, source);

    printf("\nRESULTS:\n");
    printf("Destination: \"%s\"\n", dest);
    printf("Canary value after copy: \"%s\"\n", canary);

    if (strcmp(canary, "CANARY") != 0) {
        printf("\n🚨 PROBLEM: Buffer overflow detected!\n");
        printf("The canary value was corrupted - memory was overwritten!\n");
    } else {
        printf("Canary intact ✓\n");
    }
}

/*
 * CHALLENGE 5: Struct Array Indexing
 *
 * EXPECTED BEHAVIOR:
 * - Access the second employee (index 1) in the array
 * - Should retrieve: ID=102, Name="Jane", Salary=55000.0
 * - Pointer arithmetic should correctly calculate struct addresses
 *
 * STRUCT LAYOUT:
 * Employee[0]: {101, "John", 50000.0}
 * Employee[1]: {102, "Jane", 55000.0}  <- Target
 * Employee[2]: {103, "Bob", 48000.0}
 *
 * INVESTIGATION HINTS:
 * - What is sizeof(Employee)? How much memory does each struct use?
 * - How should pointer arithmetic work with structs?
 * - What's the difference between (Employee*) and (int*) arithmetic?
 * - Use GDB to examine the memory layout of the struct array
 * - Compare the calculated address with the actual employee address
 */
typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;

void bug_struct_indexing() {
    printf("\n=== CHALLENGE 5: Struct Array Indexing ===\n");
    Employee employees[3] = {
        {101, "John", 50000.0},
        {102, "Jane", 55000.0},
        {103, "Bob", 48000.0}
    };

    printf("Employee array:\n");
    printf("employees[0]: ID=%d, Name=%s, Salary=%.2f\n",
           employees[0].id, employees[0].name, employees[0].salary);
    printf("employees[1]: ID=%d, Name=%s, Salary=%.2f  <- TARGET\n",
           employees[1].id, employees[1].name, employees[1].salary);
    printf("employees[2]: ID=%d, Name=%s, Salary=%.2f\n\n",
           employees[2].id, employees[2].name, employees[2].salary);

    printf("Trying to access employees[1] using pointer arithmetic...\n");

    Employee* calculated_emp = (Employee*)((int*)employees + 2);
    Employee* correct_emp = &employees[1];

    printf("RESULTS:\n");
    printf("Expected: ID=102, Name=Jane, Salary=55000.0\n");
    printf("Pointer arithmetic: ID=%d, Name=%s, Salary=%.2f %s\n",
           calculated_emp->id, calculated_emp->name, calculated_emp->salary,
           (calculated_emp->id == 102) ? "✓" : "❌");
    printf("Direct access: ID=%d, Name=%s, Salary=%.2f ✓\n",
           correct_emp->id, correct_emp->name, correct_emp->salary);

    if (calculated_emp->id != 102) {
        printf("\n🚨 PROBLEM: Pointer arithmetic points to wrong employee!\n");
        printf("Got ID %d instead of 102 (Jane)\n", calculated_emp->id);
    }
}

/*
 * CHALLENGE 6: Array Parameter Confusion
 *
 * EXPECTED BEHAVIOR:
 * - Process all 8 elements of the array
 * - Print each element: arr[0]=10, arr[1]=20, ..., arr[7]=80
 * - Function should correctly determine the number of elements
 *
 * THE SITUATION:
 * - Array has 8 elements: {10, 20, 30, 40, 50, 60, 70, 80}
 * - Function tries to use sizeof() to determine element count
 * - Something goes wrong with the size calculation
 *
 * INVESTIGATION HINTS:
 * - What happens to arrays when passed as function parameters?
 * - Compare sizeof(numbers) in main vs sizeof(arr) in the function
 * - What is "array decay"?
 * - How should you properly pass array size information?
 * - Use GDB to examine the values of sizeof() in both contexts
 */

void process_array(int arr[], int size) {
    printf("Inside process_array function:\n");
    int calculated_size = sizeof(arr) / sizeof(int);
    printf("sizeof(arr): %zu bytes\n", sizeof(arr));
    printf("sizeof(int): %zu bytes\n", sizeof(int));
    printf("Calculated elements: %d\n", calculated_size);
    printf("Passed size parameter: %d\n", size);

    if (calculated_size != size) {
        printf("🚨 MISMATCH: Calculated %d but expected %d elements!\n\n",
               calculated_size, size);
    }

    printf("Processing elements using sizeof calculation:\n");
    for (int i = 0; i < calculated_size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\nElements processed: %d (should be %d)\n", calculated_size, size);
}

void bug_array_parameter() {
    printf("\n=== CHALLENGE 6: Array Parameter Confusion ===\n");
    int numbers[8] = {10, 20, 30, 40, 50, 60, 70, 80};

    printf("In main function:\n");
    int main_elements = sizeof(numbers) / sizeof(int);
    printf("sizeof(numbers): %zu bytes\n", sizeof(numbers));
    printf("sizeof(int): %zu bytes\n", sizeof(int));
    printf("Calculated elements: %d\n", main_elements);
    printf("Expected: Should process all 8 elements\n\n");

    process_array(numbers, 8);

    printf("\n🚨 PROBLEM: Function processed wrong number of elements!\n");
    printf("Expected 8 elements, but sizeof() gave different result in function.\n");
}



int main() {
    printf("ARRAY DEBUGGING CHALLENGES\n");
    printf("==========================\n");
    printf("Six functions with array-related bugs to discover and fix.\n");
    printf("Use GDB to investigate each challenge!\n\n");

    printf("🔍 DEBUGGING WORKFLOW:\n");
    printf("1. Run this program to see the incorrect behavior\n");
    printf("2. Use GDB to investigate each function\n");
    printf("3. Identify the bug and understand why it happens\n");
    printf("4. Fix the code and verify your solution\n\n");

    printf("🚀 START DEBUGGING:\n");
    printf("   gdb ./buggy_arrays\n");
    printf("   (gdb) break bug_array_bounds\n");
    printf("   (gdb) run\n");
    printf("   (gdb) step\n\n");

    printf("📖 See README.md for detailed investigation hints!\n");
    printf("==================================================\n");

    // Run all challenge functions
    bug_array_bounds();
    bug_2d_array_access();
    bug_string_arrays();
    bug_buffer_overflow();
    bug_struct_indexing();
    bug_array_parameter();

    printf("\n🎯 CHALLENGE COMPLETE!\n");
    printf("Did you find and understand all 6 bugs?\n");
    printf("Try fixing them and running your corrected version!\n");

    return 0;
}
