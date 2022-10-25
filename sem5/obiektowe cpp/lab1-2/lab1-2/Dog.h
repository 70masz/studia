#pragma once
#include "Animal.h"
class Dog :
    public Animal
{
private:
    std::string breed;
    unsigned int levelOfGuideSkills;
    unsigned int levelOfTrackerSkills;

public:
    Dog();
    Dog(std::string breed, unsigned int levelOfGuideSkills, unsigned int levelOfTrackerSkills, unsigned int limbNr, std::string name, bool protectedAnimal);
    //Dog(unsigned int limbNr, std::string name, bool protectedAnimal);
    void setSkillLevel(unsigned int type, unsigned int value);
    unsigned int getSkillLevel(unsigned int type);
    void giveVoice();
    void info();
};

