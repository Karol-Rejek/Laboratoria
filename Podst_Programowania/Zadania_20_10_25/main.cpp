#include <iostream>
#include <vector>


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

void task3()
{
    //to be implemented
}

int main() 
{
    //task1();
    //task2();
    task3();
    return 0;
}