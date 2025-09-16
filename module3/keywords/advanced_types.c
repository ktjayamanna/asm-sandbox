/*
 * advanced_types.c - Demonstrates advanced C type keywords
 * Keywords covered: struct, union, enum, typedef
 */

#include <stdio.h>
#include <string.h>

// enum - enumeration (named integer constants)
enum Day {
    MONDAY,     // 0
    TUESDAY,    // 1
    WEDNESDAY,  // 2
    THURSDAY,   // 3
    FRIDAY,     // 4
    SATURDAY,   // 5
    SUNDAY      // 6
};

// enum with explicit values
enum Status {
    ERROR = -1,
    SUCCESS = 0,
    PENDING = 1,
    COMPLETE = 2
};

// struct - structure (groups related data together)
struct Student {
    char name[50];
    int age;
    float gpa;
    enum Day favorite_day;
};

// union - stores different data types in same memory location
union Data {
    int integer;
    float decimal;
    char character;
};

// typedef - creates new type names (aliases)
typedef int Age;                    // Age is now an alias for int
typedef struct Student Student_t;   // Student_t is alias for struct Student
typedef enum Day Weekday;          // Weekday is alias for enum Day

// typedef with struct definition
typedef struct {
    float x;
    float y;
} Point;  // Point is the new type name

// typedef for function pointers
typedef int (*Calculator)(int, int);

// Functions for function pointer example
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int main(void) {
    printf("=== C Advanced Types Examples ===\n\n");

    // enum examples
    printf("=== Enum Examples ===\n");
    enum Day today = FRIDAY;
    enum Status task_status = SUCCESS;
    
    printf("Today is day number: %d\n", today);
    printf("Task status: %d\n", task_status);
    
    // Using enum in switch
    switch (today) {
        case MONDAY:
        case TUESDAY:
        case WEDNESDAY:
        case THURSDAY:
            printf("It's a weekday\n");
            break;
        case FRIDAY:
            printf("TGIF!\n");
            break;
        case SATURDAY:
        case SUNDAY:
            printf("It's the weekend!\n");
            break;
    }
    printf("\n");

    // struct examples
    printf("=== Struct Examples ===\n");
    struct Student student1;
    strcpy(student1.name, "Alice");
    student1.age = 20;
    student1.gpa = 3.8f;
    student1.favorite_day = FRIDAY;
    
    printf("Student: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.1f\n", student1.gpa);
    printf("Favorite day: %d\n", student1.favorite_day);
    
    // Struct initialization
    struct Student student2 = {"Bob", 19, 3.5f, SATURDAY};
    printf("\nStudent 2: %s, Age: %d, GPA: %.1f\n", 
           student2.name, student2.age, student2.gpa);
    printf("\n");

    // union examples
    printf("=== Union Examples ===\n");
    union Data data;
    
    // All members share the same memory location
    data.integer = 42;
    printf("As integer: %d\n", data.integer);
    
    data.decimal = 3.14f;
    printf("As float: %.2f\n", data.decimal);
    printf("Integer value now corrupted: %d\n", data.integer);
    
    data.character = 'A';
    printf("As character: %c\n", data.character);
    printf("Float value now corrupted: %.2f\n", data.decimal);
    
    printf("Union size: %zu bytes (size of largest member)\n", sizeof(union Data));
    printf("\n");

    // typedef examples
    printf("=== Typedef Examples ===\n");
    
    // Using typedef aliases
    Age person_age = 25;  // Age is typedef for int
    Student_t student3 = {"Charlie", 21, 3.9f, MONDAY};
    Weekday weekend_day = SUNDAY;
    
    printf("Person age (typedef int): %d\n", person_age);
    printf("Student (typedef struct): %s\n", student3.name);
    printf("Weekend day (typedef enum): %d\n", weekend_day);
    
    // Using typedef struct without original struct name
    Point origin = {0.0f, 0.0f};
    Point destination = {10.5f, 20.3f};
    
    printf("Origin: (%.1f, %.1f)\n", origin.x, origin.y);
    printf("Destination: (%.1f, %.1f)\n", destination.x, destination.y);
    
    // Function pointer typedef
    Calculator calc_func = add;
    printf("Addition: %d\n", calc_func(5, 3));
    
    calc_func = multiply;
    printf("Multiplication: %d\n", calc_func(5, 3));
    printf("\n");

    // Nested structures
    printf("=== Nested Structures ===\n");
    typedef struct {
        Point top_left;
        Point bottom_right;
    } Rectangle;
    
    Rectangle rect = {{0.0f, 10.0f}, {5.0f, 0.0f}};
    printf("Rectangle: (%.1f,%.1f) to (%.1f,%.1f)\n",
           rect.top_left.x, rect.top_left.y,
           rect.bottom_right.x, rect.bottom_right.y);

    return 0;
}

/*
 * Key Points:
 * 
 * enum:
 * - Creates named integer constants
 * - Values start at 0 by default, increment by 1
 * - Can specify explicit values
 * - Makes code more readable than magic numbers
 * 
 * struct:
 * - Groups related data together
 * - Members accessed with dot operator (.)
 * - Can be initialized with braces {}
 * - Each member has its own memory location
 * 
 * union:
 * - All members share the same memory location
 * - Only one member can hold a value at a time
 * - Size equals the largest member
 * - Useful for memory-efficient data representation
 * 
 * typedef:
 * - Creates aliases for existing types
 * - Makes code more readable and maintainable
 * - Commonly used with structs, enums, and function pointers
 * - Can simplify complex type declarations
 */
