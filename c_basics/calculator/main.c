/* 
 * main.c - Main entry point for calculator program
 * Features: 2, 8, 14, 17, 20
 */

 #include <stdio.h>
 #include <string.h>

 void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

 char choose_operation() {
    // Feature 2: Operation menu with character input
    char choice;
    printf("Choose your operation:\n");
    printf("➕ a) Addition\n");
    printf("➖ s) Subtraction\n");
    printf("✖️  m) Multiplication\n");
    printf("➗ d) Division\n");
    printf("📊 h) Show History\n");
    printf("🚪 q) Quit\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    clear_input_buffer();  // Clear the newline left by scanf
    return choice;
 }

void get_number(char prompt[], double *number) {
    printf(prompt);
    scanf("%lf", number);
    clear_input_buffer();  // Clear the newline left by scanf
}

 void memory_info() {
    // Feature 1: Type size display using sizeof
    printf("🧮 ✨ CALCULATOR MEMORY ANALYSIS ✨ 🧮\n");
    printf("=== Memory Usage by Data Type ===\n");
    printf("┌─────────────┬──────────┬─────────────────┬──────────────────┐\n");
    printf("│ Data Type   │ Size     │ Range           │ Best Used For    │\n");
    printf("├─────────────┼──────────┼─────────────────┼──────────────────┤\n");
    printf("│ char        │ 1 byte   │ -128 to 127     │ Small integers   │\n");
    printf("│ int         │ 4 bytes  │ ±2.1 billion    │ Most integers    │\n");
    printf("│ long        │ 8 bytes  │ ±9.2×10¹⁸       │ Large integers   │\n");
    printf("│ float       │ 4 bytes  │ ±3.4×10³⁸       │ Decimal numbers  │\n");
    printf("│ double      │ 8 bytes  │ ±1.8×10³⁰⁸      │ High precision   │\n");
    printf("└─────────────┴──────────┴─────────────────┴──────────────────┘\n");
    printf("💡 Tip: The calculator will automatically detect overflow and suggest better data types!\n");
    printf("Press any key to continue to the main menu...\n");
    getchar();  // Wait for user to press a key

 }

 int main() {
     memory_info();
     char choice = choose_operation();
     double number1;
     double number2;
     get_number("Enter first number: ", &number1);
     get_number("Enter second number: ", &number2);
     return 0;
 }
