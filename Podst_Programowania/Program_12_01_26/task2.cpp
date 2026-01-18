#include <iostream>
#include <vector>

bool isIntNumber(const std::string *str)
{
    if(str->empty()) return false;
    
    int start = 0;
    if((*str)[0] == '-')
    {
        if(str->length() == 1) return false;
        start = 1;
    }

    for(int i = start; i < str->length(); i++)
    {
        if((*str)[i] < '0' || (*str)[i] > '9')
        {
            return false;
        }
    }
    return true;
}

bool loadIntNumber(int *number)
{
    std::string userInput;
    std::cin >> userInput;

    if(userInput.empty() || !isIntNumber(&userInput))
    {
        return true;
    }

    *number = std::stoi(userInput);
    return false;
}

int divide(int a, int b)
{
    return a / b;
}

int main()
{
    std::vector<int> numbers(2);
    bool blad;

    for(int i = 0; i < 2; i++)
    {
        blad = loadIntNumber(&numbers[i]);
        if(blad)
        {
            printf("Invalid input. Please enter an integer number.\n");
            i--;
        }
    }

    if(!blad)
    {
        if(numbers[1] == 0)
        {
            printf("Error: Cannot divide by zero!\n");
        }
        else
        {
            printf("Result: %d\n", divide(numbers[0], numbers[1]));
        }
    }

    return 0;
}