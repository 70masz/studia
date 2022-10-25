#pragma once
#include "Person.h"
class Teacher :
    public Person
{
private:
    int experience;
    std::string title;
public:
    Teacher(std::string name1, std::string surname1, int age1, int experience1, std::string title1);
    Teacher();
    void setTitle(std::string title1);
    int getExperience();
    bool is_Phd();
    void showInfoTeacher();
};

