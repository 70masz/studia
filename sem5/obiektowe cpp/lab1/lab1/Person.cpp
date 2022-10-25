#include "Person.h"

Person::Person(std::string name1, std::string surname1, int age1)
{
	name = name1;
	surname = surname1;
	age = age1;
	std::cout << "Konstruktor klasy bazowej - Person" << std::endl;
	}
Person::Person()
{
	std::cout << "Konstruktor bez. klasy bazowej – Person" << std::endl;
}
void Person::setAge(int age1)
{
	age = age1;
}
std::string Person::getSurname()
{
	return surname;
}
bool Person::is_18()
{
	if (age >= 18)
		return true;
	else
		return false;
}
void Person::showInfoPerson()
{
	std::cout << "Imie: " << name << " nazwisko: " << surname << " wiek: " << age << std::endl;
}
void Person::init(std::string name1, std::string surname1, int age1)
{
	name = name1;
	surname = surname1;
	age = age1;
}