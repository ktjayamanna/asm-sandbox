#include <stdio.h>

int main() {
    char *type1 = "Hello World";
    char type2[] = "Hello World";

    int *ptr = type1;
    printf("%p pints to %d\n", ptr, *ptr);

    return 0;
}
