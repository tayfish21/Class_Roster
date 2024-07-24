//============================================================================
// Course: SCRIPTING AND PROGRAMMING - APPLICATIONS — C867
// Language: C++
// Student ID: 011028610
// Name: Taylor Fisher




//============================================================================




#include <iostream>
#include "Roster.h"
using namespace std;

int main() {

	//Create an instance of the Roster class called classRoster
	Roster classRoster;

	const string studentData[] =

			{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			 "A5,Taylor,Fisher,tfis175@wgu.edu.com,30,20,39,40,SOFTWARE"
			};



	for (const auto& data: studentData) {
		classRoster.parse(data);
	};
	cout << "Showing student data: ";
	classRoster.printAll();
	cout << endl;

	for (int i = 0; i < 3; i++) {
	cout << "Showing by Degree Program: " << degreeTypeStrings[i] << std::endl;
	classRoster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "Showing invalid email addresses: ";
	cout << classRoster.printInvalidEmails();
	cout << endl;

	cout << "Showing average days in course: ";
	cout << classRoster.printAverageDaysInCourse("A2");
	cout << endl;




	return 0;

}
