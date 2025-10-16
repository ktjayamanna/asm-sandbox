#include <stdio.h>

void my_func(int *ptr)
{
    printf("I am inside\n");
    printf("%d\n", ptr[1]);
}

int main()
{
    int a = 9;
    int *ptr = &a;
    my_func(ptr);

    return 0;
}
