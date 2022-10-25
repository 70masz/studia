#include "Animal.h"

Animal::Animal(){}

Animal::Animal(unsigned int limbNr, std::string name, bool protectedAnimal = true)
{
	this->limbNr = limbNr;
	this->name = name;
	this->protectedAnimal = protectedAnimal;
}

unsigned int Animal::getLimbNr()
{
	return limbNr;
}

std::string Animal::getName()
{
	return name;
}

bool Animal::getProtectedAnimal()
{
	return protectedAnimal;
}

void Animal::setLimbNr(unsigned int limbNr)
{
	this->limbNr = limbNr;
}

void Animal::setName(std::string name)
{
	this->name = name;
}

void Animal::setProtectedAnimal(bool protectedAnimal)
{
	this->protectedAnimal = protectedAnimal;
}

void Animal::giveVoice()
{
	std::cout << "Chrum, miau, hau, piiiii\n";
}

void Animal::info()
{
	std::cout << "limbNr: " << limbNr << " name: " << name << " protectedAnimal: " << protectedAnimal << " ";
}
