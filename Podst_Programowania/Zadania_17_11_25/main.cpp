#include <iostream>

/*
int main() 
{
    int n;
    std::cin >> n;

    int tab[n];
    for (int i = 0; i <= n; i++)
    {
        std::cin >> tab[i];
    }
    
    return 0;
}*/

/*int main()
{
    int tab[10];
    for (int i = 0; i < 5; i++)
    {
        std::cin >> tab[i];
    }

    int sum = 0;
    for (int i : tab)
    {
        sum += i; 
    }
    int average = sum / 10;

    return 0;
}*/

/*int main()
{
    char name[5];
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Hello, " << name << "!\n";
    return 0;
}*/

/*int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int liczba = 123456;
    
    for (int i = 0; i <= 5; i++)
    {
        a[i] = 0;
    }
    std::cout << "Liczba= " << liczba << std::endl;
    return 0;
}*/

int avg(int tab[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += tab[i]; 
    }
    int average = sum / n;
    return average;
}

int main()
{
    int n;
    std::cin >> n;
    int tab[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> tab[i];
    }

    std::cout << "Average: " << avg(tab,n) << std::endl;
    return 0;
}