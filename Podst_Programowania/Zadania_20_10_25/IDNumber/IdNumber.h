#include <iostream>
#include <algorithm>

class IdNumber
{
private:
    std::string idNumber;

public:
    IdNumber(std::string id);
    void Validate();

private:
    void ValidateLength();
    void ValidateIfNumbers();
    void ValidateControlNumber();
};