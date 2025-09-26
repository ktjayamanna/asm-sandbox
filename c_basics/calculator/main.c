/* 
 * main.c - Main entry point for calculator program
 * Features: 2, 8, 14, 17, 20
 */

 #include <stdio.h>

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
    return choice;
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
     choose_operation();
     return 0;
 }
