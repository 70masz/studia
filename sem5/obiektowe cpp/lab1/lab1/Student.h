#pragma once
#include "Person.h"
class Student :
    public Person
{
private:
    std::string index;

public:
    Student();

    Student(std::string name1, std::string surname1, int age1, std::string index);

    void setIndex(std::string newIndex);

    std::string getIndex();

    void showInfoStudent();
};

