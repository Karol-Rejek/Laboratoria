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

int loadIntNumber()
{
    std::string userInput;
    std::cin >> userInput;

    if(userInput.empty() || !isIntNumber(&userInput))
    {
        throw -1;
    }

    return std::stoi(userInput);
}

int devide(int a, int b)
{
    return a / b;
}

int main()
{
    std::vector<int> numbers(2);
    bool blad;

    for(int i = 0; i < 2; i++)
    {
        try
        {
            numbers[i] = loadIntNumber();
            blad = false;
        }
        catch(int e)
        {
            blad = true;
            if(e == -1) // invalid input
            {
                printf("Invalid input. Please enter an positive integer number.\n");
                i--;
            }
        }
    }

    if(!blad)
    {
        printf("Result: %d\n", devide(numbers[0], numbers[1]));
    }

    return 0;
}