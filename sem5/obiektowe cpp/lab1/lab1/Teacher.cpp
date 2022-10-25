#include "Teacher.h"

Teacher::Teacher(std::string name1, std::string surname1, int age1, int experience1, std::string title1) : Person(name1, surname1, age1)
{
	experience = experience1;
	title = title1;
	std::cout << "Konstruktor klasy pochodnej Teacher" << std::endl;
}
Teacher::Teacher()
{
	std::cout << "Konstruktor bez. klasy pochodnej Teacher" << std::endl;
}
void Teacher::setTitle(std::string title1)
{
	title = title1;
}
int Teacher::getExperience()
{
	return experience;
}
bool Teacher::is_Phd()
{
	if (title == "Phd")
		return true;
	else
		return false;
}
void Teacher::showInfoTeacher()
{
	showInfoPerson();
	std::cout << "Staz pracy: " << experience << " tytul naukowy: " << title << std::endl;
}