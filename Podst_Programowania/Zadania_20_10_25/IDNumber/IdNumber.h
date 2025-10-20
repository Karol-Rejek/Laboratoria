#include <iostream>

class IdNumber
{
private:
    std::string idNumber;
public:
    IdNumber(std::string id);

private:

void Validate();
void ValidateLength();
void ValidateIfNumbers();
void ValidateControlNumber();
};