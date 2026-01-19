#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int parseStringToInt(const std::string *str)
{
    try
    {
        int result = std::stoi(*str);
        return result;
    }
    catch (const std::invalid_argument&)
    {
        throw -2;
    }
    catch (const std::out_of_range&)
    {
        throw -2;
    }
}

bool isNumber(std::string str)
{
    for(auto c : str)
    {
        if(c < '0' || c > '9')
        {
            return false;
        }
    }
    return true;
}

int multiply(int a, int b)
{
    return a * b;
}

int multiplyNumbers(std::vector<int> numbers, int range)
{
    int result = numbers[1];
    for(int i = 2; i <= range; i++)
    {
        result = multiply(result, numbers[i]);
    }
    return result;
}

std::ifstream loadFile(std::string filePath) // funkcja wczytująca plik
{
    std::ifstream file(filePath);
    return file;
}

std::vector<int> setNumbers(std::ifstream *file) // funkcja wczytująca dane z pliku i przypisujące je do kolekcji
{
    std::vector<int> data;
    std::string line;

    if(!file->is_open())
    {
        throw -1;
    }

    while(std::getline(*file,line))
    {
        if(isNumber(line))
        {
            data.push_back(parseStringToInt(&line));
        }
        else
        {
            throw -2;
        }
    }

    return data;
}

int main()
{
    int result = 0; // wybrałem typ int ponieważ program nie zakłada przekroczenia zakresu a wyjście poza zaktes typu int powinno zwrócić błąd
    bool error;
    try
    {
        std::ifstream file = loadFile("file.txt");
        std::vector<int> numbers = setNumbers(&file); // wykorzystałem vector ponieważ może on zachowywać się jak tablica oraz bardzo fleksyjny w zmianie liczby przechowywanych w nim danych
        result = multiplyNumbers(numbers, numbers[0]);
        error = false;
    }
    catch(int e)
    {
        if(e == -1)
        {
            error = true;
            printf("Invalid file input!\n");
        }
        if(e == -2)
        {
            error = true;
            printf("Invalid number!\n");
        }
    }
    
    if(!error)
    {
        printf("Result: %d\n", result);
    }
    
    return 0;
}