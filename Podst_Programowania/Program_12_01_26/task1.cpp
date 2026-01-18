#include <iostream>
#include <vector>

bool isIntNumber(const std::string *str)
{
    for(char c : *str)
    {
        if(c < '0' || c > '9')
        {
            return false;
        }
    }
    return true;
}

/*int loadIntNumber(int *number)
{
    std::string userInput;
    std::cin >> userInput;

    if(userInput.empty() || !isIntNumber(&userInput))
    {
        return -1;
    }

    *number = std::stoi(userInput);
    return 0;
}*/

int liadIntNumber()
{
    int x;
    std::cin >> x;
    if(x < 0)
    {
        throw -1;
    }
    return x;
}

int loadIntNumber(int *number)
{
    int x;
    std::cin >> x;
    if(x < 0)
    {
        return -1;
    }
    *number = x;
    return 0;
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
        blad = loadIntNumber(&numbers[i]);
        if(blad)
        {
            printf("Invalid input. Please enter an positive integer number.\n");
            i--;
        }
    }
    

    if(!blad)
    {
        printf("Result: %d\n", devide(numbers[0], numbers[1]));
    }

    return 0;
}