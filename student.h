#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "degree.h"

class Student
{
public:
    static int numInstance;
	Student();
	virtual ~Student();
    //setters
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    virtual void setDegree(Degree degree) = 0;
    
    //getters
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    virtual Degree getDegreeProgram() = 0;

    //print
    virtual void print();

 protected:    
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[3];
	Degree degree;
};
#endif
