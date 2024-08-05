#include "Student.h"
#include "DegreeProgram.h"
#include <iostream>



Student::Student()
	{
		this->studentId = "";
		this->firstName = "";
		this->lastName = "";
		this->emailAddress = "";
		this->age = 0;
		this->degree = DegreeProgram::SOFTWARE;
		for(int i = 0; i < arrayDaysInCourse; i++) {
			this-> daysInCourse[i] = 0;
		}
	}


//constructor
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, DegreeProgram degree, int daysInCourse[])
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->degree = degree;
	for(int i = 0; i< arrayDaysInCourse; i++) {
		this-> daysInCourse[i] = daysInCourse[i];
	}

}
//destructor
Student::~Student() {}


//getters
string Student::getStudentId()const {return this->studentId; }
string Student::getFirstName()const {return this->firstName; }
string Student::getLastName()const {return this->lastName; }
string Student::getEmailAddress()const {return this->emailAddress; };
int Student::getAge()const {return this->age; }
DegreeProgram Student::getDegree()const {return this->degree; };
const int* Student::getDaysInCourse()const{return this->daysInCourse; };


//setters
void Student::setStudentId(string studentId){this->studentId = studentId; }
void Student::setFirstName(string firstName){this->firstName = firstName; }
void Student::setLastName(string lastName){this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress){this->emailAddress = emailAddress; };
void Student::setAge(int age){this->age = age; }
void Student::setDegree(DegreeProgram degree){this->degree = degree; };
void Student::setDaysInCourse(const int daysInCourse[]){
	for (int i = 0; i < arrayDaysInCourse; ++i ) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}



void Student::print()
{
	std::cout << this->getStudentId() << "\t";
	std::cout << this->getFirstName() << "\t";
	std::cout << this->getLastName() << "\t";
	std::cout << this->getEmailAddress() << "\t";
	std::cout << degreeTypeStrings[this->getDegree()] << "\t";
	std::cout << this->getDaysInCourse()[0] << ",";
	std::cout << this->getDaysInCourse()[1] << ",";
    std::cout << this->getDaysInCourse()[2] << std::endl;
}


