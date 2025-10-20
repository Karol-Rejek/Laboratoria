#include <iostream>

void task1()
{
    int a = -1;
    int b = 0;
    int c = 1;

    if(a)
    {
        printf("a == true\n");
    }
    if(b)
    {
        printf("b == true\n");
    }
    if(c)
    {
        printf("c == true\n");
    }
}

void task2_for() 
{
    for (int i = 0; i <= 20; i++)
    {
        if(i % 2 == 0)
        {
            printf("%i\n", i);
        }
    }
    
}

void task2_while() 
{
    int i = 0;
    while (i <= 20)
    {
        if(i % 2 == 0)
        {
            printf("%i\n", i);
        }
        i++;
    }
}

void task2_do_while() 
{
    int i = 0;
    do
    {
        if(i % 2 == 0)
        {
            printf("%i\n", i);
        }
        i++;
    } while (i <= 20);
}

void task3() 
{
    for (int i = 30; i >= 20; i--)
    {
        printf("%i\n", i);
    }
    
}

void task4() 
{
    float bigNumber = 100.0f;
    while (bigNumber >= 0.00004f)
    {
        bigNumber /= 2.0f;
    }
    printf("Final number: %f\n", bigNumber);
    
}

int main() {
    printf("task1\n");
    task1();
    printf("\ntask2 for\n");
    task2_for();
    printf("\ntask2 while\n");
    task2_while();
    printf("\ntask2 do while\n");
    task2_do_while();
    printf("\ntask3\n");
    task3();
    printf("\ntask4\n");
    task4();
    return 0;
}