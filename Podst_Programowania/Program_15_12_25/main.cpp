# include <iostream>
# include <vector>

#include "arytmetyka.h"
#include "tablice.h"

std::vector<int> userInputs()
{
    int a, b;
    std::printf("Podaj dwie liczby calkowite: ");
    std::cin >> a >> b;
    return {a, b};
}

int main()
{
    std::vector<int> inputs;

    while (true)
    {
        std::printf("Podaj co chcesz zrobic:\n1. Operacje (+,-,*,/)\n2. Operacje na tablicach\n3. Mnozenie\n4. Dzielenie\n0. Wyjscie\n");
        int choice;
        std::cin >> choice;
    
        switch(choice) 
        {
            case 1:
                arytmatyka(1);
                break;
            case 2:
                tablice(1);
                break;
            case 3:
                
                break;
            case 4:
                
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