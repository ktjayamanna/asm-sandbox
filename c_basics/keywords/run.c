#include <stdio.h>
#include <string.h>

// String manipulation functions
char *reverse_string(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
  return str;
}

char *uppercase_string(char *str) {
  for (int i = 0; str[i]; i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] -= 32;
  }
  return str;
}

char *remove_vowels(char *str) {
  int j = 0;
  for (int i = 0; str[i]; i++) {
    char c = str[i];
    if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' &&
        c != 'E' && c != 'I' && c != 'O' && c != 'U') {
      str[j++] = str[i];
    }
  }
  str[j] = '\0';
  return str;
}

// Validation functions
int is_valid_age(int age) { return age >= 0 && age <= 150; }
int is_valid_score(int score) { return score >= 0 && score <= 100; }
int is_prime(int n) {
  if (n < 2)
    return 0;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return 0;
  return 1;
}
int is_palindrome_num(int n) {
  int original = n, reversed = 0;
  while (n > 0) {
    reversed = reversed * 10 + n % 10;
    n /= 10;
  }
  return original == reversed;
}

// Comparison functions for sorting
int compare_ascending(int a, int b) { return a - b; }
int compare_descending(int a, int b) { return b - a; }
int compare_by_digit_sum(int a, int b) {
  int sum_a = 0, sum_b = 0;
  while (a > 0) {
    sum_a += a % 10;
    a /= 10;
  }
  while (b > 0) {
    sum_b += b % 10;
    b /= 10;
  }
  return sum_a - sum_b;
}

// Transformation functions
int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }
int fibonacci(int n) {
  return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}
int count_bits(int n) {
  int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

// ============================================================================
// PRACTICE 1: String transformer with function pointer
// TODO: Write a function that takes a string manipulation function pointer
// Function pointer signature: char* (*)(char*)
// Apply it to the input string and print the result
// ============================================================================

typedef char *(*string_reversal)(char *);

void apply_string_transform(string_reversal f_ptr, char *input) {
  // TODO: call the function pointer and print result
  f_ptr(input);
}

// ============================================================================
// PRACTICE 2: Array of validator function pointers
// TODO: Create an array of 4 validation function pointers
// Each takes (int) and returns int (boolean)
// Initialize with: is_prime, is_palindrome_num, is_valid_age, is_valid_score
// Test each validator with the number 17
// ============================================================================
void practice_validators() {
  printf("\n=== PRACTICE 2: Validator Array ===\n");
  // TODO: Declare array of function pointers here
  // ??? validators[4] = {...};

  // TODO: Test each validator with 17 and print results
}

// ============================================================================
// PRACTICE 3: Function returning a comparator function pointer
// TODO: Return a comparison function based on sort_type
// 0 -> compare_ascending, 1 -> compare_descending, 2 -> compare_by_digit_sum
// Return type: pointer to function taking (int, int) returning int
// ============================================================================
// ??? get_comparator(int sort_type) {
//   // TODO: implement
// }

// ============================================================================
// PRACTICE 4: Bubble sort with custom comparator
// TODO: Implement bubble sort that takes a comparison function pointer
// The comparator should take (int, int) and return int
// Use it to determine swap order
// ============================================================================
// void bubble_sort(int arr[], int size, ???) {
//   // TODO: implement bubble sort using the comparator
// }

// ============================================================================
// PRACTICE 5: Filter array with predicate function pointer
// TODO: Write a function that filters an array based on a predicate
// Predicate signature: int (*)(int) - returns 1 to keep, 0 to discard
// Store matching elements in result array, return count of matches
// ============================================================================
// int filter_array(int arr[], int size, int result[], ???) {
//   // TODO: implement filtering logic
// }

// ============================================================================
// PRACTICE 6: Struct representing a data processor
// TODO: Define struct "Processor" with:
// - A function pointer that transforms int -> int
// - A char* description
// - An int threshold value
// ============================================================================
// struct Processor {
//   // TODO: add function pointer for int -> int transformation
//   // TODO: add description
//   // TODO: add threshold
// };

void practice_processor() {
  printf("\n=== PRACTICE 6: Data Processor ===\n");
  // TODO: Create Processor with factorial, "Factorial Calculator", threshold 10
  // TODO: Apply it to numbers 1-5
}

// ============================================================================
// PRACTICE 7: Map function - apply transformation to array
// TODO: Write a map function that takes:
// - Input array, size, output array
// - A transformation function pointer: int (*)(int)
// Apply the transformation to each element
// ============================================================================
// void map_array(int input[], int size, int output[], ???) {
//   // TODO: implement map logic
// }

// ============================================================================
// PRACTICE 8: Chain string transformations
// TODO: Take an array of string transformation function pointers
// Apply each transformation in sequence to the string
// Each function: char* (*)(char*)
// ============================================================================
// char *chain_string_transforms(char *str, ???, int count) {
//   // TODO: apply each transformation in sequence
// }

// ============================================================================
// PRACTICE 9: Reduce/fold operation with function pointer
// TODO: Implement reduce that takes:
// - Array, size, initial value
// - A binary operation function pointer: int (*)(int, int)
// Accumulate result by applying operation to accumulator and each element
// ============================================================================
// int reduce_array(int arr[], int size, int initial, ???) {
//   // TODO: implement reduce logic
// }

// ============================================================================
// PRACTICE 10: Function dispatcher - returns different function based on input
// TODO: Based on operation_code, return appropriate transformation function
// 'f' -> factorial, 'b' -> count_bits, 'F' -> fibonacci
// Return type: pointer to function taking int returning int
// ============================================================================
// ??? get_transformer(char operation_code) {
//   // TODO: implement dispatcher
// }

int main() {
  printf("=== Function Pointer Practice Exercises ===\n");
  printf("Uncomment and implement each practice section!\n");

  // Uncomment as you complete each practice:
  // practice_array();
  // practice_struct();

  // Test your implementations here
  char my_input[] = "Nebraska";
  apply_string_transform(&reverse_string, my_input);
  printf("New str is %s", my_input);

  return 0;
}