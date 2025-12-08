#include <iostream>
int a = 5, b = 5;

void add() //dla tej wersji nie zmienia się wartość zmiennych w main
{
    printf("%d\n", a + b);
}

void add(int a, int b) //dla tej wersji nie zmienia się wartość zmiennych w main
{
    a = a + b;
    printf("%d\n", a);
}

void add_(int &a, int &b) //dla tej wersji zmienia się wartość zmiennych w main
{
    a = a + b;
    printf("%d\n", a);
}

void add__(int* a, int* b) //dla tej wersji zmienia się wartość zmiennych w main
{
    printf("%d\n", *a + *b);
}

int main()
{
    add();
    int x = 5, y = 5;
    add(x,y);
     printf("Using pointers: %d\n", x);
    add_(x,y);
    printf("Using pointers: %d\n", x);
    add__(&x,&y);
    return 0;
}