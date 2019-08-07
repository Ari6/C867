#ifndef ROSTER_H
#define ROSTER_H

#include "degree.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

class Roster
{
public:
	Roster();
	~Roster();
    void convertStudentData(std::string* studentData);
    void add(std::string studentID, std::string firstName,
                std::string lastName, std::string emailAddress, int age,
                int daysIncourse1, int daysInCourse2, int daysInCourse3,
                Degree degree);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();  // an @, and periods are okay, should not
                                // include space.
    void printByDegreeProgram(int degreeProgram);  // prints only augument degree
    Student* classRosterArray[5];
};

#endif
