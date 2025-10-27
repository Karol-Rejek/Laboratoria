#include <iostream>

#pragma region Zadanie 1
void task1()
{
    int a,b;
    std::cin >> a >> b;
    printf("Suma: %i\n", a + b);
    printf("Różnica: %i\n", a - b);
    printf("Iloczyn: %i\n", a * b);
    if (b != 0)
    {
        printf("Iloraz: %i\n", a / b);
    }
    else
    {
        printf("Nie można dzielić przez zero!\n");
    }
    printf("Reszta z dzielenia: %i\n", a % b);
}
#pragma endregion

#pragma region Zadanie 2
void task2()
{
    int a = 5;
    int b = 2;
    int c = 3;

    int tabResults[4] = 
    {
        a + b * c, //11
        (a + b) * c, //21
        a / b + c, //5
        a % b + c //4
    };

    for (int i = 0; i < 4; i++)
    {
        printf("Wynik %i: %i\n", i + 1, tabResults[i]);
    }
}
#pragma endregion

#pragma region Zadanie 3
void task3()
{
    int celcius;
    std::cin >> celcius;
    printf("Fahrenheit: %i\n", celcius * 9 / 5 + 32);
}
#pragma endregion

#pragma region Zadanie 4
void task4()
{
    int x = 5;
    printf("%d\n", x++); // 5
    printf("%d\n", x); // 6

    int y = 5;
    printf("%d\n", ++y); // 6
    printf("%d\n", y); // 6
}
#pragma endregion

#pragma region Zadanie 5
void task5()
{
    int a = 10, b = 5, c = 2;

    int tabResults[6] =
    {
        a + b + c, // 17
        a * b + c, // 52
        a / b + c * 2, // 6
        a % 3 + b / 2, // 3
        (a + b) / c, // 7
        a + b / c * 2, // 14
    };

    for(auto tabResult : tabResults)
    {
        printf("Wynik: %i\n", tabResult);
    }
}
#pragma endregion

#pragma region Zadanie 6
void task6()
{
    int a = 5, b = 10;

    printf("%d\n", a < b); //1
    printf("%d\n", a > b); //0
    printf("%d\n", a == b); //0
    printf("%d\n", a != b); //1
    printf("%d\n", a <= 5); //1
    printf("%d\n", b >= 10); //1

}
#pragma endregion

#pragma region Zadanie 7
void task7()
{
    int a = 5, b = 10, c = -3;
    printf("%d\n", a && b); //1
    printf("%d\n", a || b); //1
    printf("%d\n", a || c); //1
    printf("%d\n", !a); //0
    printf("%d\n", !!a); //1
}
#pragma endregion

#pragma region Zadanie 8
void task8()
{
    int a , b;
    int max = a > b ? a : b;
}
#pragma endregion

int main()
{
    int taskNumber;
    printf("Podaj numer zadania (1-8): ");
    std::cin >> taskNumber;

    switch (taskNumber)
    {
    case 1:
        task1();
        break;

    case 2:
        task2();
        break;

    case 3:
        task3();
        break;

    case 4:
        task4();
        break;

    case 5:
        task5();
        break;

    case 6:
        task6();
        break;

    case 7:
        task7();
        break;

    case 8:
        task8();
        break;

    default:
        break;
    }

    return 0;
}