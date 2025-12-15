#include <iostream>
#include <vector>

#include "arytmetyka.h"
#include "tablice.h"
#include "macierze.h"

int main()
{
    std::vector<int> inputs;

    while (true)
    {
        std::printf("Podaj co chcesz zrobic:\n1. Operacje (+,-,*,/)\n2. Operacje na tablicach\n3. Oparacje na macierzach\n0. Wyjscie\n");
        int choice;
        std::cin >> choice;
    
        switch(choice) 
        {
            case 1:
                arytmatyka();
                break;
            case 2:
                tablice();
                break;
            case 3:
                macierze();
                break;
            case 0:
                exit(0);
                break;
            default:
                std::printf("Niepoprawny wybor!\n");
        }   
    }
    return 0;
}