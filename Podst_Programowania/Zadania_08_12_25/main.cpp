#include <iostream>
using namespace std;

void secret()
{
    cout << "SECRET FUNCION, NOT CALLED FROM ANYWHERE!" << endl;
}

void func()
{
    cout << "NORMAL FUNCTION" << endl;
}

int main()
{
    func();
    cout << "END OF MAIN" << endl;
    return 0;
}