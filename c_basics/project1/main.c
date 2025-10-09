#include <stdio.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void get_number(char prompt[], float *num_ptr) {
    int invalid_input = 1;

    do{
        printf(prompt);
        if (scanf("%f", num_ptr) != 1) {
            clear_input_buffer();
            printf("Invalid input! Please try again.\n");
            invalid_input = 1;
        }
        else {
            invalid_input = 0;
        }
    } while(invalid_input);
}

void choose_operation( char *choice) {
    printf("Choose your operation:\n");
    printf("a) Addition\n");
    printf("s) Subtraction\n");
    printf("m) Multiplication\n");
    printf("d) Division\n");
    printf("Enter choice: ");
    scanf(" %c", choice);
    clear_input_buffer();  // Clear the newline left by scanf
}

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

void get_boolean(char prompt[], int *bool_ptr) {
    int invalid_input = 1;

    do{
        printf(prompt);
        if (scanf("%d", bool_ptr) != 1) {
            clear_input_buffer();
            printf("Invalid input! Please try again.\n");
            invalid_input = 1;
        }
        else {
            invalid_input = 0;
        }
    } while(invalid_input);
}

int main(){
    printf("Welcome to the calculator!\n");
    int repeat = 1;
    while (repeat) {
        float num1 = 0.0, num2 = 0.0, ans = 0.0;
        char choice = '\0';
        get_number("Enter first number: ", &num1);
        get_number("Enter second number: ", &num2);
        int valid_choice = 0;
        while (!valid_choice) {
            choose_operation(&choice);
            switch (choice) {
                case 'a':
                    valid_choice = 1;
                    addtion(num1, num2, &ans);
                    break;
                case 's':
                    valid_choice = 1;
                    subtraction(num1, num2, &ans);
                    break;
                case 'm':
                    valid_choice = 1;
                    multiplication(num1, num2, &ans);
                    break;
                case 'd':
                    valid_choice = 1;
                    division(num1, num2, &ans);
                    break;
                default:
                    printf("Invalid choice!\n");
                    valid_choice = 0;
            }
        }
        printf("Result: %f\n", ans);
        get_boolean("Do you want to continue? (1/0):", &repeat);
        if (repeat == 0) {
            break;
        }
        clear_input_buffer();
    }
    return 0;
}