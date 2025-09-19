#include <stdio.h>
#include <math.h>

int main() {
    // Example 1: Decimal fraction imprecision
    float f = 0.1f;
    double d = 0.1;
    
    printf("0.1 as float: %.20f\n", f);
    printf("0.1 as double: %.20lf\n", d);
    
    // Example 2: Accumulation error
    float sum = 0.0f;
    for (int i = 0; i < 10; i++) {
        sum += 0.1f;
    }
    printf("10 * 0.1 = %.10f (should be exactly 1.0)\n", sum);
    printf("Equal to 1.0? %s\n", sum == 1.0f ? "Yes" : "No");
    
    // Example 3: Comparison problems
    double a = 0.1 + 0.2;
    double b = 0.3;
    printf("0.1 + 0.2 == 0.3? %s\n", a == b ? "Yes" : "No");
    printf("0.1 + 0.2 = %.20lf\n", a);
    printf("0.3 = %.20lf\n", b);
    
    return 0;
}