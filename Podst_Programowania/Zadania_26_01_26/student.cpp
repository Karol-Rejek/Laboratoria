#include <iostream>
#include <vector>

struct student
{
    std::string name;
    int age;
    int height;
};

int avgHeight(std::vector<student>* students)
{
    int totalHeight = 0;
    for (const auto& student : *students)
    {
        totalHeight += student.height;
    }
    return totalHeight / students->size();
}

int maxHeightStudent(std::vector<student>* students)
{
    int maxHeight = 0;
    for (const auto& student : *students)
    {
        if (student.height > maxHeight)
        {
            maxHeight = student.height;
        }
    }
    return maxHeight;
}

std::string tallestStudentName(std::vector<student>* students)
{
    int maxHeight = maxHeightStudent(students);
    for (const auto& student : *students)
    {
        if (student.height == maxHeight)
        {
            return student.name;
        }
    }
    return "";
}

void actualizeStudentsAges(std::vector<student>* students)
{
    for (auto& student : *students)
    {
        student.age++;
    }
}

void printStudentInfo(const student& s)
{
    printf("Name: %s, Age: %d, Height: %d\n", s.name.c_str(), s.age, s.height);
}

int main()
{
    std::vector<student> students={
        {"Marek", 20, 180},
        {"Tomek", 22, 170},
        {"Adam", 19, 165},
        {"Maciej", 26, 175},
        {"Tadeusz", 30, 180}
    };

    printf("Average height: %d\n", avgHeight(&students));
    printf("Tallest student: %s / %d\n", tallestStudentName(&students).c_str(), maxHeightStudent(&students));
    actualizeStudentsAges(&students);
    for (const auto& s : students)
    {
        printStudentInfo(s);
    }
    
    return 0;
}