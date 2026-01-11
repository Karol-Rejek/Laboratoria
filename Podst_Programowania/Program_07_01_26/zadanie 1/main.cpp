#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

// 1. zły format pliku (inny niż .txt)
// 2. plik nie istnieje
// 3. błąd podczas odczytu pliku
// 4. zła ścieżka do pliku
// 5. plik jest pusty
// 6. plik zawiera dane inne niż liczby całkowite
// 7. liczba n nie jest zgodna z ilością podanych liczb
// 8. liczba n jest ujemna lub równa zero
// 9. plik zawiera puste linie lub spacje

std::string trim(const std::string& str)
{
    auto start = std::find_if_not(str.begin(), str.end(), [](unsigned char c) { 
        return std::isspace(c); 
    });
    
    auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char c) { 
        return std::isspace(c); 
    }).base();
    
    return (start < end) ? std::string(start, end) : std::string();
}

bool isInteger(const std::string& str)
{
    if (str.empty()) return false;
    
    int start = 0;
    if (str[0] == '-' || str[0] == '+') start = 1;
    
    if (start == str.length()) return false;
    
    for (int i = start; i < str.length(); i++) {
        if (std::isdigit(str[i]) == 0) return false;
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
    for (int i = filePath.length(); i > 0; i--)
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
        line = trim(line);
        if (line.empty() || !isInteger(line))
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

std::pair<bool, int> parseStringToInt(const std::string& str)
{
    try
    {
        int result = std::stoi(str);
        return {true, result};
    }
    catch (const std::invalid_argument&)
    {
        return {false, 0};
    }
    catch (const std::out_of_range&)
    {
        return {false, 0};
    }
}

std::pair<bool, std::vector<int>> fileData(std::ifstream& file)
{
    std::vector<int> data;
    std::string line;
    
    while (std::getline(file, line))
    {
        if (file.fail())
        {
            return {false, {}};
        }
        
        line = trim(line);
        if (line.empty())
        {
            continue;
        }
        
        auto [success, value] = parseStringToInt(line);
        if (!success)
        {
            return {false, {}};
        }
        data.push_back(value);
    }
    
    if (file.bad())
    {
        return {false, {}};
    }
    
    return {true, data};
}

std::string validateFileContent(std::ifstream& file)
{
    if (!file.is_open())
    {
        return "Cannot open file";
    }

    if (checkIfFileEmpty(file))
    {
        return "File is empty";
    }
    
    file.clear();
    file.seekg(0);
    
    if(!checkIfFileContainsOnlyIntegers(file))
    {
        return "File contains non-integer values or empty lines";
    }

    file.clear();
    file.seekg(0);

    auto [dataSuccess, data] = fileData(file);
    if (!dataSuccess || data.empty())
    {
        return "Error reading file or converting integers";
    }
    
    int n = data[0];
    if(checkIfNValueIs0rNegative(n))
    {
        return "N value is 0 or negative";
    }

    if(!checkIfNValueMatchesCount(n, data.size() - 1))
    {
        return "N value does not match the count of numbers";
    }

    return "";
}

std::pair<bool, std::string> fileValidation(const std::string& filePath)
{
    if(!checkIfFileExists(filePath))
    {
        return {false, "File does not exist or path is invalid."};
    }

    if(!checkFileFormat(filePath))
    {
        return {false, "Invalid file format. Only .txt files are allowed."};
    }

    std::ifstream file(filePath);

    std::string contentError = validateFileContent(file);
    if(contentError != "")
    {
        return {false, contentError};
    }

    return {true, ""};
}

#pragma region UnitTests
std::vector<std::string> getTestFiles() // funnkcja odpowiedzialna za wybór jakie testy bedą przepwadzone przez wybranie pliku.
{
    return {
        "file1.txt", // wartość ujemna n
        "file2.txt", // wartość n = 0
        "file3.txt", // n nie jest liczbą całkowitą (plik zawiera tekst)
        "file4.txt", // n nie zgadza się z ilością podanych liczb
        "file5.txt", // plik pusty
        "file6.doc", // zły format pliku
        "file7.txt", // plik zawiera spacje i puste linie
        "file8.txt", // plik nie istnieje/zła ścieżka
        "filegood.txt" // poprawny plik
    };
}

void printStartingTestsMessage()
{
    printf("========== UNIT TESTS ==========\n\n");
}

void printTestResult(const std::string& filePath, bool passed, const std::string& errorMessage)
{
    printf("Test: %s\n", filePath.c_str());
    printf("-------------------------------------------\n");

    if (passed)
    {
        printf("✓ TEST POWIÓDŁ SIĘ\n");
    }
    else
    {
        printf("✗ TEST NIE POWIÓDŁ SIĘ\n");
        printf("Błąd: %s\n", errorMessage.c_str());
    }

    std::cout << std::endl;
}

void printTestSummary(int passedTests, int failedTests)
{
    printf("=========== TESTS SUMMARY ===========\n");
    printf("Tests passed: %d\n", passedTests);
    printf("Tests failed: %d\n", failedTests);
    printf("Total tests: %d\n", (passedTests + failedTests));
    printf("=====================================\n");
}

void runUnitTests()
{
    std::vector<std::string> testFiles = getTestFiles();

    printStartingTestsMessage();

    int passedTests = 0;
    int failedTests = 0;

    for (const auto& filePath : testFiles)
    {
        auto [testPassed, errorMessage] = fileValidation(filePath);
        printTestResult(filePath, testPassed, errorMessage);

        if (testPassed)
        {
            passedTests++;
        }
        else
        {
            failedTests++;
        }
    }

    printTestSummary(passedTests, failedTests);
}
#pragma endregion

int main()
{
    runUnitTests(); // Uruchomienie testów jednostkowych

    // Komantarz: Najlepszym zastosowaniem dla testów byłoby wywołanie każdej funkcji/pliku osobno 
    // w dostosowanym środowisku testowym (np. przy użyciu cMake), jednak ze względu
    // na ograniczenia projektu testy zostały zintegrowane w jedną funkcję runUnitTests().

    return 0;
}