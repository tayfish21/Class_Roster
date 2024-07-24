#include "Student.h"
#include "DegreeProgram.h"


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
	cout << this->getStudentId() << "\t";
	cout << this->getFirstName() << "\t";
	cout << this->getLastName() << "\t";
	cout << this->getEmailAddress() << "\t";
	cout << degreeTypeStrings[this->getDegree()] << "\t";
	cout << this->getDaysInCourse()[0] << ",";
	cout << this->getDaysInCourse()[1] << ",";
    cout << this->getDaysInCourse()[2] << std::endl;
}


