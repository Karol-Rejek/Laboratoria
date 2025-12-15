#include "arytmetyka.h"

# include <iostream>
# include <vector>

# include "dodaj.h"
# include "odejmij.h"
# include "pomnoz.h"
# include "podziel.h"

std::vector<int> userInputs()
{
    int a, b;
    std::printf("Podaj dwie liczby calkowite: ");
    std::cin >> a >> b;
    return {a, b};
}
int arytmatyka(int k)
{
    std::vector<int> inputs;
    
    while (true)
    {
        std::printf("Podaj co chcesz zrobic:\n1. Dodawanie\n2. Odejmowanie\n3. Mnozenie\n4. Dzielenie\n0. Wyjscie\n");
        int choice;
        std::cin >> choice;
    
        switch(choice) 
        {
            case 1:
                inputs = userInputs();
                printf("Wynik: %d\n", dodaj(inputs[0], inputs[1]));
                break;
            case 2:
                inputs = userInputs();
                printf("Wynik: %d\n", odejmij(inputs[0], inputs[1]));
                break;
            case 3:
                inputs = userInputs();
                printf("Wynik: %d\n", pomnoz(inputs[0], inputs[1]));
                break;
            case 4:
                inputs = userInputs();
                printf("Wynik: %d\n", podziel(inputs[0], inputs[1]));
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