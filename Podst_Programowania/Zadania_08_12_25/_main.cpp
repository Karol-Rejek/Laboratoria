#include <iostream>

int func1(int a)
{
    return 1;
}

int func2(int a)
{
    return 2;
}

int func3(int a)
{
    func2(a);
    return 3;
}

int main()
{
    int output = 5;

    output = func1(66666);
    output = func3(7);

    std::cout << output;
    return 0;
}