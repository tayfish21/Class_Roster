#include "Roster.h"
#include<string>
#include <sstream>
#include <iostream>


void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degree)
{

	int parr[3] = {days1, days2, days3};

	numOfStudentsArray[++lastIndex] = new Student(studentId, firstName, lastName, emailAddress, age, degree, parr);
}

void Roster::parse(string studentData) {

	std::stringstream ss (studentData);
	std::string placeHolder;

	//end of student ID
	std::getline(ss, placeHolder, ',');
	std::string studentId = placeHolder;

	//end of first name
	std::getline(ss, placeHolder, ',');
	std::string firstName = placeHolder;

	//end of last name
	std::getline(ss, placeHolder, ',');
	std::string lastName = placeHolder;

	//end of email address
	std::getline(ss, placeHolder, ',');
	std::string emailAddress = placeHolder;

	//end of age (age variable) turning to string
	std::getline(ss, placeHolder, ',');
	int age = std::stoi(placeHolder);

	//end of days of course Day1 (d1) turning to string
	std::getline(ss, placeHolder, ',');
	int days1 = std::stoi(placeHolder);

	//end of days of course Day2 (d2) turning to string
	std::getline(ss, placeHolder, ',');
	int days2 = std::stoi(placeHolder);

	//end of days of course Day3 (d3) turning to string
	std::getline(ss, placeHolder, ',');
	int days3 = std::stoi(placeHolder);

	//find degree program (degree program)
	std::getline(ss, placeHolder, ',');
	DegreeProgram degree = NETWORK;
	if (placeHolder == "SECURITY") degree = SECURITY;
	else if (placeHolder == "SOFTWARE") degree = SOFTWARE;

	add(studentId, lastName, firstName, emailAddress, age, days1, days2, days3, degree);
}


//prints all students
void Roster::printAll() {
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << numOfStudentsArray[i]->getStudentId() << '\t';
		cout << numOfStudentsArray[i]->getFirstName() << '\t';
		cout << numOfStudentsArray[i]->getLastName() << '\t';
		cout << numOfStudentsArray[i]->getEmailAddress() << '\t';
		cout << numOfStudentsArray[i]->getAge()<< '\t';
		cout << numOfStudentsArray[i]->getEmailAddress()<< '\t';
		cout << numOfStudentsArray[i]->getDaysInCourse()[0] << '\t';
		cout << numOfStudentsArray[i]->getDaysInCourse()[1] << '\t';
		cout << numOfStudentsArray[i]->getDaysInCourse()[2] << '\t';
		cout << degreeTypeStrings[numOfStudentsArray[i]->getDegree()] << std::endl;


	}
}
//showing by certain degree match
void Roster::printByDegreeProgram(DegreeProgram degree) {


	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::numOfStudentsArray[i]->getDegree() == degree) numOfStudentsArray[i]->print();
	}
	cout << std::endl;
}

//A valid email should include an at sign ('@') and period ('.') and should not include a space (' '). Will print out invalid email and student ID if incorrect
void Roster::printInvalidEmails() {
    bool any = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        string emailAddress = numOfStudentsArray[i]->getEmailAddress();
        if (emailAddress.find('@') == string::npos ||
            emailAddress.find('.') == string::npos ||
            emailAddress.find(' ') != string::npos) {
            any = true;
            cout << emailAddress << ": " << numOfStudentsArray[i]->getStudentId() << std::endl;
        }
    }
    if (!any) {
        cout << "None" << std::endl;
    }
}
//printing average number of days in the three courses
void Roster::printAverageDaysInCourse(string studentId) {

	for (int i = 0; i<=lastIndex; i++) {
		cout << numOfStudentsArray[i]->getStudentId() << ": ";
		cout << (numOfStudentsArray[i]->getDaysInCourse()[0]) + numOfStudentsArray[i]->getDaysInCourse()[1] + numOfStudentsArray[i]->getDaysInCourse()[2] / 3.0 << std::endl;
	}
	cout << std::endl;
}

//removes students from the roster by student ID. If the student ID does not exist, error will print
void Roster::remove(string studentId)
{
	bool success = false;
    for (int i = 0; i <= lastIndex; i++) {
        if(numOfStudentsArray[i]->getStudentId() == studentId) {
            success = true;
            if(i < lastIndex)
            {
                Student* temp = numOfStudentsArray[i];
                numOfStudentsArray[i] = numOfStudentsArray[numOfStudents -1];
                numOfStudentsArray[numOfStudents - 1] = temp;
            }
            lastIndex--;
            break; //leave loop after finding student
        }
    }
			if (success) {
				cout << studentId << " removed from the Roster" << std::endl;
            } else
            {
				cout << studentId << " not found" << std::endl;
		}
	}

//destructor
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
            delete numOfStudentsArray[i];
            numOfStudentsArray[i] = nullptr;
        }
    }




