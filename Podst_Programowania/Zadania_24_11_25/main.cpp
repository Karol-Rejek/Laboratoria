#include <iostream>

void task1()
{
    int x = 5;
    int* p = &x;

    printf(" %d\n", *p); // 5
    printf(" %p\n", p); // adres x
    printf(" %p\n", &p); // adres p
}

void task2()
{
    int x = 10;
    int* p = &x;

    *p = *p + 7;
    printf(" %d\n", x); // 17
    *p = *p + 1;
    printf(" %d\n", x); // 18
}

void task3()
{
    int arr[] = {2, 4, 6, 8};
    int* p = arr;

    p++;
    printf(" %d\n", *p); // 4
    p += 2;
    printf(" %d\n", *p); // 8
}

void task4()
{
    int arr[] = {10, 20, 30, 40};
    int* p = arr;
    int* end = arr + 4;

    while (p < end)
    {
        std::cout << *p << " ";
        p++;
    }
}

void task5()
{
    int* data = new int[10];
    data = new int[20];
    delete[] data;
}

int* create(bool ok)
{
    int* a = new int(123);
    if (!ok)
    {
        return nullptr; // wyciek
    }
    return a;
} 

int main()
{
    //task1();
    //task2();
    //task3();
    //task4();

    

    return 0;
}

/*int main()
{
    int liczba = 5;
    char znak = 'A';
    double liczbaDouble = 3.14;
    int *wskInt;
    char *wskChar;
    double *wskDouble;

    printf("%d\n", sizeof(wskInt));
    printf("%d\n", sizeof(wskChar));
    printf("%d\n", sizeof(wskDouble));

    printf("%d\n", sizeof(liczba));
    printf("%d\n", sizeof(znak));
    printf("%d\n", sizeof(liczbaDouble));
    return 0;
}*/

/*int main()
{
    int liczba = 5;
    int *wsk;
    wsk = &liczba;
    return 0;
}*/