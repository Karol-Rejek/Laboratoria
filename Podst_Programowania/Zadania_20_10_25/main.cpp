#include <iostream>
#include <vector>
#include <algorithm>

#pragma region Zadanie 1
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
#pragma endregion

#pragma region Zadanie 2
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
#pragma endregion

#pragma region Zadanie 3
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
#pragma endregion

#pragma region Zadanie 4
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
#pragma endregion

#pragma region Zadanie 5

class IdNumber
{
private:
    std::string idNumber;

public:
    IdNumber(std::string id)
    {
        idNumber = id;
    }   

    void Validate()
    {
        if (ValidateLength() && ValidateIfNumbers() && ValidateControlNumber())
        {
            printf("PESEL jest prawidłowy.\n");
        }
    }

private:
    bool ValidateLength()  
    {
        if (idNumber.length() != 11)
        {
            throw std::invalid_argument("PESEL musi mieć dokładnie 11 znaków.");
        }
        return true;
    }

    bool ValidateIfNumbers()
    {
        if (!std::all_of(idNumber.begin(), idNumber.end(), ::isdigit))
        {
            throw std::invalid_argument("PESEL musi zawierać wyłącznie cyfry.");
        }
        return true;
    }

    bool ValidateControlNumber()
    {
        int controlSum = idNumber[10] - '0';
        int sum = 0;
        int tab[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

        for (int i = 0; i < idNumber.length() - 1; i++)
        {
            sum += (idNumber[i] - '0') * tab[i];
        }

        if (10 - (sum % 10) != controlSum)
        {
            throw std::invalid_argument("Nieprawidłowy numer kontrolny PESEL.");
        }
        return true;
    }
};

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
#pragma endregion


int main() 
{
    char task;
    printf("Podaj numer zadania (1-5): ");
    std::cin >> task;

    switch (task)
    {
    case '1':
        task1();
        break;
    case '2':
        task2();
        break;
    case '3':
        task3();
        break;
    case '4':
        task4();
        break;
    case '5':
        task5();
        break;
    default:
        break;
    }
    return 0;
}