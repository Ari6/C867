// C867.cpp : This file contains the 'main' function. Program execution begins
// and ends there. Ayumu Suzuki April 20 2019 v 0.1

#include <iostream>
#include <sstream>
#include <string>

#include "roster.h"

int main() {
	const std::string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ayumu,Suzuki,asuzuk2@wgu.edu,35,10,15,5,SOFTWARE"
	};

	/*
	Main function that comes from F
	*/
	/*
	F.1
		Print out to the screen
		1. course title
		2. programming language used
		3. your studentID and your name
	*/
	std::cout << "Course: Scripting and Programming - Applications - C867"<< std::endl;
	std::cout << "Language: C++" << std::endl;
	std::cout << "Student ID: 001094398  Name: Ayumu Suzuki" << std::endl;

	/*
	F.2
	create instance of Roster class called classRoster
	*/
	Roster* classRoster = new Roster;

	/*
	F.3
	Add each student to classRoster
	*/
	std::string tempStudentID = "";
	std::string tempFirstName = "";
	std::string tempLastName = "";
	std::string tempEmailAddress = "";
	std::string temp = "0";
	int tempAge = 0;
	int tempDaysInCourse1 = 0;
	int tempDaysInCourse2 = 0;
	int tempDaysInCourse3 = 0;
	Degree tempDegree = Degree::NA;

	for (int i = 0; i < 5; ++i) {
		std::istringstream inSS(studentData[i]);
		std::getline(inSS, tempStudentID, ',');
		std::getline(inSS, tempFirstName, ',');
		std::getline(inSS, tempLastName, ',');
		std::getline(inSS, tempEmailAddress, ',');
		std::getline(inSS, temp, ',');
		tempAge = std::stoi(temp);
		std::getline(inSS, temp, ',');
		tempDaysInCourse1 = std::stoi(temp);
		std::getline(inSS, temp, ',');
		tempDaysInCourse2 = std::stoi(temp);
		std::getline(inSS, temp, ',');
		tempDaysInCourse3 = std::stoi(temp);
		std::getline(inSS, temp, ',');
		if (temp == "SECURITY") {
			tempDegree = Degree::SECURITY;
		} else if (temp == "NETWORK") {
			tempDegree = Degree::NETWORK;
		} else if (temp == "SOFTWARE"){
			tempDegree = Degree::SOFTWARE;
		} else {
			tempDegree = Degree::NA;
		}
		classRoster->add(tempStudentID, tempFirstName, tempLastName,
						 tempEmailAddress, tempAge, tempDaysInCourse1,
						 tempDaysInCourse2, tempDaysInCourse3, tempDegree);
	}
	/*
	F.4
	convert pseudo code
	*/
	std::cout << " ######  printAll run  ######" << std::endl;
	classRoster->printAll();

	std::cout << std::endl << " ######  printInvalidEmails run  ######" << std::endl;
	classRoster->printInvalidEmails();

	std::cout << std::endl << " ######  printAverageDaysInCourse run  ######" << std::endl;
	for (int i = 0; i < 5; ++i) {
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
	}
	std::cout << std::endl << " ######  printByDegreeProgram run  ######" << std::endl;
	classRoster->printByDegreeProgram(Degree::SOFTWARE);

	std::cout << std::endl << " ######  remove run 1st ######" << std::endl;
	classRoster->remove("A3");

	std::cout << std::endl << " ######  remove run 2nd ######" << std::endl;
	classRoster->remove("A3");
	/*
	 * F.5 call destructor to release Roster memory
	 * */
	delete classRoster;

	return 0;
}


Roster::Roster() {
}

Roster::~Roster() {
	delete *classRosterArray;
}

void Roster::printAll() {
	for (int i = 0; i < 5; ++i) {
		if (this->classRosterArray[i] != nullptr) {
    		this->classRosterArray[i]->print();
		}
	}
}
void Roster::printAverageDaysInCourse(std::string studentID) {
	for (int i = 0; i < 5; ++i) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			int temp = 0;
			int* ret = nullptr;
        	ret = this->classRosterArray[i]->getDaysInCourse();
            for (int k = 0; k < 3; k++) {
            	temp += *(ret + k);
            }
        	std::cout << "ID: " << studentID << "  Average: " << temp / 3 << std::endl;
		}
	}
}

void Roster::printInvalidEmails() {
	std::string emailCheck = "";
	for (int i = 0; i < 5; ++i) {
		bool errorFlag = false;
        emailCheck = this->classRosterArray[i]->getEmailAddress();
		if (emailCheck.find(' ') != std::string::npos) {
            errorFlag = true;
        } else if (emailCheck.find('@') == std::string::npos) {
            errorFlag = true;
        } else if (emailCheck.find('@') != emailCheck.rfind('@')) {
			errorFlag = true;
        } else if (emailCheck.find('.') != emailCheck.rfind('.')) {
			errorFlag = true;
		}

        if (errorFlag) {
			std::cout << "Invalid email: " << emailCheck << std::endl;
        }
	}
}

void Roster::printByDegreeProgram(int degreeProgram) {
	for (int i = 0; i < 5; ++i) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
}

void Roster::add(std::string studentID, std::string firstName,
                 std::string lastName, std::string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3,
                 Degree degree) {

    if (degree == Degree::SECURITY) {
        this->classRosterArray[Student::numInstance] = new SecurityStudent;
    } else if (degree == Degree::NETWORK) {
        this->classRosterArray[Student::numInstance] = new NetworkStudent;
    } else {
        this->classRosterArray[Student::numInstance] = new SoftwareStudent;
    }

    this->classRosterArray[Student::numInstance]->setStudentID(studentID);
    this->classRosterArray[Student::numInstance]->setFirstName(firstName);
    this->classRosterArray[Student::numInstance]->setLastName(lastName);
    this->classRosterArray[Student::numInstance]->setEmailAddress(emailAddress);
    this->classRosterArray[Student::numInstance]->setAge(age);
    this->classRosterArray[Student::numInstance]->setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
    Student::numInstance += 1;
}

void Roster::remove(std::string studentID) {
	bool deleteFlag = false;
	for (int i = 0; i < 5; ++i) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			this->classRosterArray[i]->setStudentID("");
			this->classRosterArray[i]->setFirstName("");
			this->classRosterArray[i]->setLastName("");
			this->classRosterArray[i]->setEmailAddress("");
			this->classRosterArray[i]->setAge(0);
			this->classRosterArray[i]->setDaysInCourse(0, 0, 0);
			this->classRosterArray[i]->setDegree(Degree::NA);
			deleteFlag = true;
		}
	}
	if (deleteFlag == false) {
		std::cout << "There is no " << studentID << " in the student data." << std::endl;
	}
}
