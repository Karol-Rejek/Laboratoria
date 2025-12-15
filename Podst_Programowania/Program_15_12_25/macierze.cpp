#include "macierze.h"
#include <iostream>
#include <vector>

std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B)
{
    int rows = A.size();
    int cols = A[0].size();
    
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));
    
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    
    return result;
}

std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B)
{
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();
    
    if (colsA != rowsB)
    {
        std::printf("Blad: liczba kolumn macierzy A musi sie rownac liczbie wierszy macierzy B!\n");
        return std::vector<std::vector<int>>();
    }
    
    std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0));
    
    for (int i = 0; i < rowsA; ++i)
    {
        for (int j = 0; j < colsB; ++j)
        {
            for (int k = 0; k < colsA; ++k)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return result;
}

void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (const auto& row : matrix)
    {
        for (int val : row)
        {
            std::printf("%d ", val);
        }
        std::printf("\n");
    }
}

std::vector<std::vector<int>> readMatrix()
{
    int rows, cols;
    
    std::printf("Podaj liczbe wierszy macierzy: ");
    std::cin >> rows;
    std::printf("Podaj liczbe kolumn macierzy: ");
    std::cin >> cols;
    
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    
    std::printf("Wprowadz elementy macierzy (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::printf("Element [%d][%d]: ", i, j);
            std::cin >> matrix[i][j];
        }
    }
    
    return matrix;
}

void macierze()
{
    std::vector<std::vector<int>> A, B;
    std::printf("Wybierz operacje na macierzach\n1. Dodawanie\n2. Mnozenie\n3. Powrot do menu\n4. Wyjscie\n");
    int choice;
    std::cin >> choice;
    auto sum= std::vector<std::vector<int>>();
    auto product = std::vector<std::vector<int>>();

    switch (choice)
    {
    case 1:
        A = readMatrix();
        std::printf("\nMacierz A:\n");
        printMatrix(A);
        B = readMatrix();
        std::printf("\nMacierz B:\n");
        printMatrix(B);
        std::printf("\nA + B =\n");
        sum = addMatrices(A, B);
        printMatrix(sum);
        break;
    case 2:
        A = readMatrix();
        std::printf("\nMacierz A:\n");
        printMatrix(A);
        B = readMatrix();
        std::printf("\nMacierz B:\n");
        printMatrix(B);
        std::printf("\nA * B =\n");
        product = multiplyMatrices(A, B);
        printMatrix(product);
        break;
    case 3:
        return;
    case 4:
        exit(0);
    default:
        std::printf("Niepoprawny wybor!\n");
        break;
    }
}