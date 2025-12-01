#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int add(int a, int b, int *result)
{
    *result = a + b;
    return 0;
}

void devide(int a, int b, int *quotient, int *rest)
{
    *rest = a % b;
    *quotient = a / b;
}

int main()
{
    int x = 7, y = 5;
    printf("%d\n", add(x, y));

    int c;
    add(x,y, &c);
    printf("Using pointers: %d\n", c);

    int rest, quotient;
    devide(x, y, &quotient, &rest);
    printf("Quotient: %d\n", quotient);
    printf("Rest: %d\n", rest);
    return 0;
}