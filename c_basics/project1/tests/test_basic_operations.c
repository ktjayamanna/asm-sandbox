#include <stdio.h>
#include <assert.h>
#include <math.h>

// Function implementations from main.c
void addtion(float a, float b, float *result) {
    *result = a + b;
}

void subtraction(float a, float b, float *result) {
    *result = a - b;
}

void multiplication(float a, float b, float *result) {
    *result = a * b;
}

void division(float a, float b, float *result) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        *result = 0;
    }
    else {
        *result = a / b;
    }
}

// Test helper function
int float_equals(float a, float b, float tolerance) {
    return fabs(a - b) < tolerance;
}

void test_addition() {
    printf("Testing addition...\n");
    float result;
    
    // Test positive numbers
    addtion(5.5, 2.5, &result);
    assert(float_equals(result, 8.0, 0.001));
    
    // Test negative numbers
    addtion(-3.0, -2.0, &result);
    assert(float_equals(result, -5.0, 0.001));
    
    // Test mixed signs
    addtion(10.0, -3.0, &result);
    assert(float_equals(result, 7.0, 0.001));
    
    // Test zero
    addtion(0.0, 5.0, &result);
    assert(float_equals(result, 5.0, 0.001));
    
    printf("Addition tests passed!\n");
}

void test_subtraction() {
    printf("Testing subtraction...\n");
    float result;
    
    // Test positive numbers
    subtraction(10.0, 3.0, &result);
    assert(float_equals(result, 7.0, 0.001));
    
    // Test negative result
    subtraction(3.0, 10.0, &result);
    assert(float_equals(result, -7.0, 0.001));
    
    // Test negative numbers
    subtraction(-5.0, -2.0, &result);
    assert(float_equals(result, -3.0, 0.001));
    
    // Test zero
    subtraction(5.0, 0.0, &result);
    assert(float_equals(result, 5.0, 0.001));
    
    printf("Subtraction tests passed!\n");
}

void test_multiplication() {
    printf("Testing multiplication...\n");
    float result;
    
    // Test positive numbers
    multiplication(4.0, 3.0, &result);
    assert(float_equals(result, 12.0, 0.001));
    
    // Test negative numbers
    multiplication(-2.0, 3.0, &result);
    assert(float_equals(result, -6.0, 0.001));
    
    // Test both negative
    multiplication(-2.0, -3.0, &result);
    assert(float_equals(result, 6.0, 0.001));
    
    // Test zero
    multiplication(5.0, 0.0, &result);
    assert(float_equals(result, 0.0, 0.001));
    
    // Test decimal
    multiplication(2.5, 4.0, &result);
    assert(float_equals(result, 10.0, 0.001));
    
    printf("Multiplication tests passed!\n");
}

void test_division() {
    printf("Testing division...\n");
    float result;
    
    // Test normal division
    division(10.0, 2.0, &result);
    assert(float_equals(result, 5.0, 0.001));
    
    // Test decimal result
    division(7.0, 2.0, &result);
    assert(float_equals(result, 3.5, 0.001));
    
    // Test negative numbers
    division(-10.0, 2.0, &result);
    assert(float_equals(result, -5.0, 0.001));
    
    // Test division by zero (should set result to 0 and print error)
    printf("Testing division by zero (should print error message):\n");
    division(10.0, 0.0, &result);
    assert(float_equals(result, 0.0, 0.001));
    
    printf("Division tests passed!\n");
}

int main() {
    printf("Running unit tests for calculator functions...\n\n");
    
    test_addition();
    test_subtraction();
    test_multiplication();
    test_division();
    
    printf("\nAll unit tests passed!\n");
    return 0;
}
