#include "Student.h"
void Student::setIndex(std::string newIndex)
{
    this->index = newIndex;
}

std::string Student::getIndex()
{
    return index;
}

Student::Student()
{
    std::cout << "konstruktor klasy student\n";
}

void Student::showInfoStudent()
{
    showInfoPerson();
    std::cout << "indeks: " << index << std::endl;
}

Student::Student(std::string name1, std::string surname1, int age1, std::string index) : Person(name1, surname1, age1)
{
    std::cout << "Konstruktor klasy Student\n";
    this->index = index;
}