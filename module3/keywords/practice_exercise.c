/*
 * practice_exercise.c - Your turn to practice C keywords!
 * 
 * Complete the TODOs below to reinforce your understanding of C keywords.
 * This exercise covers all 32 C keywords in practical scenarios.
 */

#include <stdio.h>

// TODO 1: Define an enum for traffic light colors (RED, YELLOW, GREEN)
// enum TrafficLight {
//     // Your code here
// };

// TODO 2: Define a struct for a book with title (char array), pages (int), and price (float)
// struct Book {
//     // Your code here
// };

// TODO 3: Create a typedef for the Book struct to make it easier to use
// typedef struct Book Book_t;

// TODO 4: Declare an extern variable (you'll define it after main)
// extern int library_count;

// TODO 5: Create a static function that counts how many times it's been called
// static int get_call_count(void) {
//     // Use a static local variable to keep track
//     // Your code here
// }

// TODO 6: Function that demonstrates const parameters
// void display_book_info(/* const Book_t* book */) {
//     // Print book information
//     // Try to modify the book parameter - it should give an error!
//     // Your code here
// }

// TODO 7: Function using register hint for a simple calculation
// int calculate_factorial(int n) {
//     // Use register variables for the loop
//     // Your code here
// }

// TODO 8: Function demonstrating switch/case/default with break
// void describe_traffic_light(/* enum TrafficLight color */) {
//     // Use switch statement with cases for each color
//     // Don't forget break statements and a default case
//     // Your code here
// }

int main(void) {
    printf("=== C Keywords Practice Exercise ===\n\n");

    // TODO 9: Create variables using different data types
    // char, int, float, double, long, short, unsigned, signed
    // Your code here

    // TODO 10: Use const to create a read-only variable
    // const double pi = 3.14159;

    // TODO 11: Demonstrate sizeof with your variables
    // Print the size of different data types
    // Your code here

    // TODO 12: Create and initialize a Book struct
    // Book_t my_book = {"C Programming", 500, 29.99f};

    // TODO 13: Use if/else statements to check book price
    // if (my_book.price > 25.0f) {
    //     printf("Expensive book!\n");
    // } else {
    //     printf("Affordable book!\n");
    // }

    // TODO 14: Use a for loop to print numbers 1-10
    // Skip even numbers using continue
    // Your code here

    // TODO 15: Use a while loop with break
    // Count down from 10, but break when you reach 5
    // Your code here

    // TODO 16: Use do-while loop
    // Ask user for input until they enter 'q' (simulate with a counter)
    // Your code here

    // TODO 17: Demonstrate union usage
    // Create a union that can hold int, float, or char
    // Show how they share memory
    // Your code here

    // TODO 18: Use goto (even though it's discouraged)
    // Create a simple retry mechanism
    // Your code here

    // TODO 19: Call your functions
    // Test get_call_count(), describe_traffic_light(), etc.
    // Your code here

    // TODO 20: Demonstrate volatile (just declare a volatile variable)
    // volatile int sensor_value = 100;

    return 0; // return keyword
}

// TODO 21: Define the extern variable you declared earlier
// int library_count = 1000;

/*
 * BONUS CHALLENGES:
 * 
 * 1. Create a function that uses all storage classes (auto, extern, register, static)
 * 2. Make a nested structure using typedef
 * 3. Create a function pointer typedef and use it
 * 4. Implement a simple state machine using enum and switch
 * 5. Use const in three different ways (variable, parameter, return value)
 * 
 * COMPILATION TEST:
 * After completing the TODOs, compile with:
 * gcc -o practice practice_exercise.c
 * 
 * If it compiles without errors, you've successfully used all C keywords!
 */

/*
 * SOLUTION HINTS:
 * 
 * - Remember to uncomment the code as you complete each TODO
 * - Pay attention to syntax: semicolons, braces, data types
 * - Test one section at a time by compiling frequently
 * - Use the other example files as reference
 * - Don't forget to initialize variables before using them
 * - enum values start at 0 by default
 * - struct members are accessed with the dot operator (.)
 * - const variables must be initialized when declared
 * - static variables retain their value between function calls
 */
