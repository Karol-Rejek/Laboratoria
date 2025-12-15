#include "tablice.h"
#include <iostream>


int sumArray(int* arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

int avgArray(int* arr, int size)
{
    if (size == 0) 
    {
        return 0;
    }
    return sumArray(arr, size) / size;
}

int minArray(int* arr, int size)
{
    if (size == 0) 
    {
        return 0;
    }
    
    int min = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int maxArray(int* arr, int size)
{
    if (size == 0) 
    {
        return 0;
    }

    int max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void tablice()
{
    int size;
    std::printf("Podaj rozmiar tablicy: ");
    std::cin >> size;

    int* tab = new int[size];

    std::printf("Podaj %d elementow tablicy:\n", size);
    for (int i = 0; i < size; ++i)
    {
        std::printf("Element %d: ", i);
        std::cin >> tab[i];
    }

    std::printf("Wybierz operacje na tablicy:\n1. Suma\n2. Srednia\n3. Minimum\n4. Maximum\n");
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::printf("Suma elementow tablicy: %d\n", sumArray(tab, size));
        break;
    case 2:
        std::printf("Srednia elementow tablicy: %d\n", avgArray(tab, size));
        break;
        case 3: 
        std::printf("Minimalny element tablicy: %d\n", minArray(tab, size));
        break;
    case 4:
        std::printf("Maksymalny element tablicy: %d\n", maxArray(tab, size));
        break;
    default:
        std::printf("Niepoprawny wybor!\n");
        break;
    }
    
    delete[] tab;
}