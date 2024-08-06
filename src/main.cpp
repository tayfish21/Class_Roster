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
    
    //printing out C867 Info
    std::string courseName = "Course Name: SCRIPTING AND PROGRAMMING - APPLICATIONS — C867";
    std::string programmingLanguage = "Language used: C++";
    std::string studentID = "Student ID: 011028610";
    std::string studenName = "Student Name: Taylor Fisher";
    
    std::cout << courseName << "|";
    std::cout << programmingLanguage << "|";
    std::cout << studentID << "|";
    std::cout << studenName << std::endl;
    std::cout << "------------------------------" << std:: endl;



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
    std::cout << "------------------------------" << std:: endl;

    cout << "Showing invalid email addresses: " << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    std::cout << "------------------------------" << std:: endl;
    
    cout << "Showing average days in course for each student: " << endl;
    for (const std::string& student : studentData) {
        long position = student.find(',');
        std::string id = student.substr(0, position);
        classRoster.printAverageDaysInCourse(id);
    }
    classRoster.printAverageDaysInCourse("");
    cout << endl;
    std::cout << "------------------------------" << std:: endl;

    cout<< "Print students in Software: "<< endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    std::cout << "------------------------------" << std:: endl;

    cout<< "Remove student with ID A3: "<< endl;
    classRoster.remove("A3");
    std::cout<<"------"<< std:: endl;
    classRoster.printAll();
    std::cout<<"------"<< std:: endl;
    classRoster.remove("A3");
    cout << endl;


    
    
	return 0;

}

