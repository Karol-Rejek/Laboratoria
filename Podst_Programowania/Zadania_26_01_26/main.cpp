#include <iostream>
#include <cmath>
#include <vector>

struct point
{
    double x;
    double y;
};

struct square
{
    point A;
    point B;
    point C;
    point D;
};


struct vector2D
{
    double x;
    double y;
};

double distance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

double distance(point* A, point* B)
{
    double dx = B->x - A->x;
    double dy = B->y - A->y;
    return std::sqrt(dx * dx + dy * dy);
}

double subtract(double a, double b)
{
    return a - b;
}

std::vector<double>* getVector(double* A, double* B)
{
    std::vector<double>* AB = new std::vector<double>(2);
    (*AB)[0] = subtract(B[0], A[0]);
    (*AB)[1] = subtract(B[1], A[1]);
    return AB;
}

vector2D getVector(point* A, point* B)
{
    vector2D AB;
    AB.x = subtract(B->x, A->x);
    AB.y = subtract(B->y, A->y);
    return AB;
}

double squareArea(square* S)
{
    double side1 = distance(&S->A, &S->B);
    double side2 = distance(&S->B, &S->C);
    return side1 * side2;
}

double squarePerimeter(square* S)
{
    double side1 = distance(&S->A, &S->B);
    double side2 = distance(&S->B, &S->C);
    return 2 * (side1 + side2);
}

int main()
{
    
    return 0;
}