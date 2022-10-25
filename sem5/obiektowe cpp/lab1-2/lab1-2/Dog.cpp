#include "Dog.h"

Dog::Dog() {}

Dog::Dog(std::string breed, unsigned int levelOfGuideSkills, unsigned int levelOfTrackerSkills, unsigned int limbNr = 4 , std::string name = "Dog", bool protectedAnimal = false) : Animal(limbNr, name, protectedAnimal)
{
	this->breed = breed;
	this->levelOfGuideSkills = levelOfGuideSkills;
	this->levelOfTrackerSkills = levelOfTrackerSkills;
}

