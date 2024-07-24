#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "DegreeProgram.h"
#include "Student.h"
using std::string;
using std::cout;


class Roster
{
private:
	int lastIndex = -1;
	const static int numOfStudents = 5;
	Student* numOfStudentsArray[numOfStudents];

public:
	void add(string studentId,
			string firstName,
			string lastName,
			string emailAddress,
			int age,
			int days1,
			int days2,
			int days3,
			DegreeProgram degree);
	void parse(string row);

	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void remove(string studentId);
	void printByDegreeProgram(DegreeProgram degree);
~Roster();
};
