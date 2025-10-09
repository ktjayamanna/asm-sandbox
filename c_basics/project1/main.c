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

int main(){
    printf("Welcome to the calculator!\n");
    float num1, num2;
    get_number("Enter first number: ", &num1);
    get_number("Enter second number: ", &num2);
    printf("num1: %f, num2: %f\n", num1, num2);
    return 0;
}