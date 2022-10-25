#pragma once
#include <iostream>
class Person
{
private:
	std::string name;
	std::string surname;
	int age;
	public:
	Person(std::string name1, std::string surname1, int age1);
	void init(std::string name1, std::string surname1, int age1);
	Person();
	void setAge(int age1);
	std::string getSurname();
	bool is_18();
	void showInfoPerson();
};

