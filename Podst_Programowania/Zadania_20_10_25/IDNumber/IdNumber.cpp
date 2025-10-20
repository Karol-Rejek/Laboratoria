#include "IdNumber.h"

IdNumber::IdNumber(std::string id)
{
    idNumber = id;
}

void IdNumber::Validate()
{
    ValidateLength();
    ValidateIfNumbers();
    ValidateControlNumber();
}

void IdNumber::ValidateLength()
{
    if (idNumber.length() != 11)
    {
        throw std::invalid_argument("PESEL musi mieć dokładnie 11 znaków.");
    }
}

void IdNumber::ValidateIfNumbers()
{
    if (!std::all_of(idNumber.begin(), idNumber.end(), ::isdigit))
    {
        throw std::invalid_argument("PESEL musi zawierać wyłącznie cyfry.");
    }
}

void IdNumber::ValidateControlNumber()
{
    int controlSum = idNumber[10] - '0';
    int sum = 0;

    for (int i = 0; i < idNumber.length() - 1; i++)
    {
        sum += (idNumber[i] - '0') * (i + 1);
    }

    if (10 - (sum % 10) != controlSum)
    {
        throw std::invalid_argument("Nieprawidłowy numer kontrolny PESEL.");
    }
}