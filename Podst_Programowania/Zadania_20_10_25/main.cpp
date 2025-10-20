#include <iostream>
#include <vector>

#include "IDNumber/IdNumber.h"


int findMax(std::vector<int> vec) 
{
    int max = vec[0];
    for (int i = 1; i < vec.size(); i++) 
    {
        if (vec[i] > max) 
        {
            max = vec[i];
        }
    }
    return max;
}

void task1()
{
    std::vector<int> numbers;
    int input;
    for (int numberAmmount = 0; numberAmmount < 3; numberAmmount++)
    {
        std::cin >> input;
        numbers.push_back(input);
    }
    printf("Max: %i\n", findMax(numbers));
}

void task2()
{
    for (int i = 1; i <= 10; i++)
    {
        printf("Tabliczka mnozenia dla %i:\n", i);
        for (int j = 1; j <= 10; j++)
        {
            printf("%i * %i = %i\n", i, j, i * j);
        }
    }
    
}

int addFrom1ToNumber(int number)
{
    int sum = 0;
    for (int i = 1; i <= number; i++)
    {
        sum += i;
    }
    return sum;
}

void task3()
{
    int n;
    std::cin >> n;
    printf("Suma liczb od 1 do %i wynosi: %i\n", n, addFrom1ToNumber(n));
}

void task4()
{
    int correctNumber = rand() % 20 + 1;
    int userNumber;

    do
    {
        std::cin >> userNumber;
        if(userNumber != correctNumber)
        {
            printf("Pudło\n");
        }
        else
        {
            printf("Gratulacje! Zgadles liczbe.\n");
        }
    } while (userNumber != correctNumber);
}

void task5()
{
    std::string peselStr;

    printf("Podaj numer PESEL\n");
    std::cin >> peselStr;

    IdNumber pesel(peselStr);

    try
    {
        pesel.Validate();
    }
    catch (const std::invalid_argument& e)
    {
        printf("Błąd: %s\n", e.what());
    }
}

int main() 
{
    //task1();
    //task2();
    //task3();
    //task4();
    task5();
    return 0;
}