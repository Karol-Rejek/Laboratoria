#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// 1. zły format pliku (inny niż .txt)
// 2. plik nie istnieje
// 3. błąd podczas odczytu pliku
// 4. zła ścieżka do pliku
// 5. plik jest pusty
// 6. plik zawiera dane inne niż liczby całkowite
// 7. liczba n nie jest zgodna z ilością podanych liczb
// 8. liczba n jest ujemna lub równa zero

bool isInteger(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

bool checkIfFileExists(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (file)
    {
        return true;
    }
    return false;
}

bool checkFileFormat(const std::string& filePath)
{
    for (int i = filePath.length(); i < 0; i--)
    {
        if (filePath.substr(i, 4) == ".txt")
        {
            return true;
        }
    }
    return false;
}

bool checkIfFileContainsOnlyIntegers(std::ifstream& file)
{
    std::string line;
    while (std::getline(file, line))
    {
        if (!isInteger(line))
        {
            return false;
        }
    }
    return true;
}

bool checkIfFileEmpty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

bool checkIfNValueIs0rNegative(int n)
{
    return n <= 0;
}

bool checkIfNValueMatchesCount(int n, int count)
{
    return n == count;
}

int parseStringToInt(const std::string& str)
{
    return std::stoi(str);
}

std::vector<int> fileData(const std::ifstream& file)
{
    std::vector<int> data;
    std::string line;
    while (std::getline(file, line))
    {
        data.push_back(parseStringToInt(line));
    }
    return data;
}

std::string validateFileContent(std::ifstream& file)
{
    if (!checkIfFileEmpty(file))
    {
        return "File is empty";
    }
    
    if(!checkIfFileContainsOnlyIntegers(file))
    {
        return "File contains non-integer values";
    }

    int n = fileData(file)[0];
    if(!checkIfNValueIs0rNegative(n))
    {
        return "N value is 0 or negative";
    }

    if(!checkIfNValueMatchesCount(n, fileData(file).size() - 1))
    {
        return "N value does not match the count of numbers";
    }
}

bool fileValidation(const std::string& filePath)
{
    if(!checkIfFileExists(filePath))
    {
        std::cout << "File does not exist or path is invalid." << std::endl;
        return false;
    }

    if(!checkFileFormat(filePath))
    {
        std::cout << "Invalid file format. Only .txt files are allowed." << std::endl;
        return false;
    }

    std::ifstream file(filePath);

    if(validateFileContent(file) != "")
    {
        std::cout << validateFileContent(file) << std::endl;
        return false;
    }
}





int main()
{
    



    return 0;
}