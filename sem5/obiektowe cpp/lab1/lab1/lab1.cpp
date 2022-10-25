#include <iostream>
#include <string>
#include "Person.h"
#include "Teacher.h"
#include "Student.h"

int main()
{
	Student statycznaStudentuwStatycznych[3];

	int iloscStudentow1 = 2;

	Student* dynamicznaStudentuwStatycznych = new Student[iloscStudentow1];

	Student* statycznaStudentuwDynamicznych[3];

	Student** dynamicznaStudentuwDynamicznych = new Student*[iloscStudentow1];

	for (int i = 0; i < iloscStudentow1; i++)
	{
		dynamicznaStudentuwStatycznych[i] = Student();
		dynamicznaStudentuwStatycznych[i].init("marek", "marucha", iloscStudentow1 * 10 + i);
		dynamicznaStudentuwStatycznych[i].setIndex(std::to_string(i));

		dynamicznaStudentuwDynamicznych[i] = new Student();
		dynamicznaStudentuwDynamicznych[i]->init("zdzislaw", "zadoluks", iloscStudentow1 * 10 + i);
		dynamicznaStudentuwDynamicznych[i]->setIndex(std::to_string(i));
	}

	for (int i = 0; i < 3; i++)
	{
		statycznaStudentuwDynamicznych[i] = new Student();
		statycznaStudentuwDynamicznych[i]->init("sally", "carrera", iloscStudentow1 * 10 + i);
		statycznaStudentuwDynamicznych[i]->setIndex(std::to_string(iloscStudentow1 + i));

		statycznaStudentuwStatycznych[i] = Student();
		statycznaStudentuwStatycznych[i].init("bolek", "przybandziak", iloscStudentow1 * 10 + i);
		statycznaStudentuwStatycznych[i].setIndex(std::to_string(iloscStudentow1 + i));
	}

	for (int i = 0; i < iloscStudentow1; i++)
	{
		dynamicznaStudentuwDynamicznych[i]->showInfoStudent();
	}

	for (int i = 0; i < iloscStudentow1; i++)
	{
		dynamicznaStudentuwStatycznych[i].showInfoStudent();
	}

	for (int i = 0; i < 3; i++)
	{
		statycznaStudentuwDynamicznych[i]->showInfoStudent();
	}

	for (int i = 0; i < 3; i++)
	{
		statycznaStudentuwStatycznych[i].showInfoStudent();
	}

	return 0;
}