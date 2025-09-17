/*
 * data_types.c - Demonstrates basic C data type keywords
 * Keywords covered: char, int, float, double, long, short, signed, unsigned, void
 */

#include <stdio.h>

// void - function that returns nothing
void print_separator(void) {
    printf("------------------------\n");
}

// int - basic integer type (usually 32 bits)
int add_numbers(int a, int b) {
    return a + b;
}

int main(void) {
    printf("=== C Data Types Examples ===\n\n");

    // char - single character (8 bits)
    char letter = 'A';
    char grade = 'B';
    printf("char examples:\n");
    printf("Letter: %c, Grade: %c\n", letter, grade);
    print_separator();

    // int - standard integer (typically 32 bits)
    int age = 25;
    int score = 95;
    printf("int examples:\n");
    printf("Age: %d, Score: %d\n", age, score);
    printf("Sum: %d\n", add_numbers(age, score));
    print_separator();

    // float - single precision floating point (32 bits)
    float temperature = 98.6f;  // Note the 'f' suffix
    float price = 19.99f;
    printf("float examples:\n");
    printf("Temperature: %.1f°F, Price: $%.2f\n", temperature, price);
    print_separator();

    // double - double precision floating point (64 bits)
    double pi = 3.14159265359;
    double distance = 384400.0;  // Distance to moon in km
    printf("double examples:\n");
    printf("Pi: %.10f, Distance to moon: %.1f km\n", pi, distance);
    print_separator();

    // short - short integer (typically 16 bits)
    short year = 2024;
    short month = 12;
    printf("short examples:\n");
    printf("Year: %hd, Month: %hd\n", year, month);
    print_separator();

    // long - long integer (typically 64 bits)
    long population = 8000000000L;  // Note the 'L' suffix
    long file_size = 1073741824L;   // 1 GB in bytes
    printf("long examples:\n");
    printf("World population: %ld, File size: %ld bytes\n", population, file_size);
    print_separator();

    // unsigned - only positive numbers (no sign bit)
    unsigned int positive_only = 4294967295U;  // Max value for 32-bit unsigned
    unsigned char byte_value = 255;            // Max value for 8-bit unsigned
    printf("unsigned examples:\n");
    printf("Max unsigned int: %u, Max unsigned char: %u\n", positive_only, byte_value);
    print_separator();

    // signed - explicitly signed (default for most types)
    signed int can_be_negative = -100;
    signed char small_signed = -128;  // Min value for signed char
    printf("signed examples:\n");
    printf("Negative int: %d, Min signed char: %d\n", can_be_negative, small_signed);
    print_separator();

    // Combining modifiers
    unsigned long big_positive = 18446744073709551615UL;  // Max 64-bit unsigned
    signed short small_range = -32768;                    // Min 16-bit signed
    printf("Combined modifier examples:\n");
    printf("Max unsigned long: %lu\n", big_positive);
    printf("Min signed short: %hd\n", small_range);

    return 0;  // int return type from main
}

/*
 * Key Points:
 * - char: Single character, 8 bits
 * - int: Standard integer, usually 32 bits
 * - float: Single precision decimal, 32 bits (use 'f' suffix)
 * - double: Double precision decimal, 64 bits (default for literals)
 * - short: Smaller integer, usually 16 bits
 * - long: Larger integer, usually 64 bits (use 'L' suffix)
 * - unsigned: Only positive values, doubles the positive range
 * - signed: Can be negative (default for most types)
 * - void: No value/type, used for functions that don't return anything
 */
