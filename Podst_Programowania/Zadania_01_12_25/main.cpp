int a = 0;

void funcC()
{
    int a = 4;
}

void funcB()
{
    int a = 3;
    funcC();
}

void funcA()
{
    int a = 2;
    funcB();
}

int main()
{
    int a = 1;
    funcA();
    return 0;
}