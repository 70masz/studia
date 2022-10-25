#pragma once
#include <iostream>
#include <string>

class Animal
{
private:
	unsigned int limbNr;
	std::string name;
	bool protectedAnimal;

public:
	Animal();
	Animal(unsigned int limbNr, std::string name, bool protectedAnimal = true);

	unsigned int getLimbNr();
	std::string getName();
	bool getProtectedAnimal();

	void setLimbNr(unsigned int limbNr);
	void setName(std::string name);
	void setProtectedAnimal(bool protectedAnimal);

	void giveVoice();
	void info();
};

