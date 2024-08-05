#pragma once
#include <string>
#include "DegreeProgram.h"


using std::string;
class Student
{
public:
    static const int arrayDaysInCourse = 3;

    // Constructors and Destructor
    Student();
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, DegreeProgram degree, int daysInCourse[]);
    ~Student();

//getters
string getStudentId() const;
string getFirstName() const;
string getLastName() const;
string getEmailAddress() const;
int getAge()const;
DegreeProgram getDegree() const;
const int* getDaysInCourse() const;


//setters
void setStudentId(string studentId);
void setFirstName(string firstName);
void setLastName(string lastName);
void setEmailAddress(string emailAddress);
void setAge(int age);
void setDegree(DegreeProgram degree);
void setDaysInCourse(const int daysInCourse[]);


static void printHeader();
void print();// print student data

private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	DegreeProgram degree;
	int daysInCourse[arrayDaysInCourse];

};
