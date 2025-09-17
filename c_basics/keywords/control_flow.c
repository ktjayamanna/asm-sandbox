/*
 * control_flow.c - Demonstrates C control flow keywords
 * Keywords covered: if, else, for, while, do, break, continue, switch, case, default, goto, return
 */

#include <stdio.h>

// return - function that returns a value
int get_grade_points(char grade) {
    // switch - multi-way branch based on value
    switch (grade) {
        // case - specific value to match in switch
        case 'A':
        case 'a':
            return 4;  // return - exit function with value
        case 'B':
        case 'b':
            return 3;
        case 'C':
        case 'c':
            return 2;
        case 'D':
        case 'd':
            return 1;
        case 'F':
        case 'f':
            return 0;
        // default - executed when no case matches
        default:
            printf("Invalid grade: %c\n", grade);
            return -1;
    }
}

void demonstrate_loops(void) {
    printf("=== Loop Examples ===\n");
    
    // for - loop with initialization, condition, and increment
    printf("for loop (counting 1 to 5):\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // while - loop with condition check at beginning
    printf("while loop (countdown from 5):\n");
    int count = 5;
    while (count > 0) {
        printf("%d ", count);
        count--;
    }
    printf("\n\n");
    
    // do - loop with condition check at end (executes at least once)
    printf("do-while loop (executes at least once):\n");
    int num = 10;
    do {
        printf("Number: %d\n", num);
        num += 5;
    } while (num < 10);  // Condition is false, but loop ran once
    printf("\n");
}

void demonstrate_break_continue(void) {
    printf("=== Break and Continue Examples ===\n");
    
    // break - exit from loop early
    printf("break example (find first even number > 10):\n");
    for (int i = 11; i <= 20; i++) {
        if (i % 2 == 0) {
            printf("Found first even number: %d\n", i);
            break;  // Exit the loop immediately
        }
    }
    printf("\n");
    
    // continue - skip to next iteration
    printf("continue example (print only odd numbers 1-10):\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers, go to next iteration
        }
        printf("%d ", i);
    }
    printf("\n\n");
}

void demonstrate_goto(void) {
    printf("=== Goto Example (generally discouraged) ===\n");
    
    int attempts = 0;
    
    // goto - unconditional jump to a label
    retry:  // Label for goto
    attempts++;
    printf("Attempt %d\n", attempts);
    
    if (attempts < 3) {
        goto retry;  // Jump back to retry label
    }
    
    printf("Done with goto example\n\n");
}

int main(void) {
    printf("=== C Control Flow Examples ===\n\n");
    
    // if/else - conditional execution
    printf("=== If/Else Examples ===\n");
    int temperature = 75;
    
    // if - execute block if condition is true
    if (temperature > 80) {
        printf("It's hot outside!\n");
    }
    // else - execute block if condition is false
    else if (temperature > 60) {
        printf("Nice weather today!\n");
    }
    else {
        printf("It's cold outside!\n");
    }
    printf("\n");
    
    // switch/case/default example
    printf("=== Switch/Case/Default Example ===\n");
    char student_grade = 'B';
    int points = get_grade_points(student_grade);
    
    if (points >= 0) {
        printf("Grade %c = %d points\n", student_grade, points);
    }
    printf("\n");
    
    // Demonstrate different types of loops
    demonstrate_loops();
    
    // Demonstrate break and continue
    demonstrate_break_continue();
    
    // Demonstrate goto (though it's generally discouraged)
    demonstrate_goto();
    
    // Nested control structures example
    printf("=== Nested Control Structures ===\n");
    for (int i = 1; i <= 3; i++) {
        printf("Outer loop iteration %d:\n", i);
        
        for (int j = 1; j <= 3; j++) {
            if (i == j) {
                printf("  Diagonal element (%d,%d)\n", i, j);
                continue;
            }
            if (i + j > 4) {
                printf("  Breaking inner loop at (%d,%d)\n", i, j);
                break;
            }
            printf("  Element (%d,%d)\n", i, j);
        }
    }
    
    return 0;  // return from main function
}

/*
 * Key Points:
 * 
 * if/else: Basic conditional execution
 * - if: execute block when condition is true
 * - else: execute alternative block when condition is false
 * 
 * Loops:
 * - for: best for counting loops with known iterations
 * - while: best when you don't know how many iterations
 * - do-while: when you need at least one execution
 * 
 * Loop control:
 * - break: exit loop immediately
 * - continue: skip to next iteration
 * 
 * Multi-way branching:
 * - switch: efficient multi-way branch
 * - case: specific values to match
 * - default: fallback when no case matches
 * 
 * Function control:
 * - return: exit function and optionally return value
 * 
 * Unconditional jump:
 * - goto: jump to labeled statement (use sparingly!)
 */
