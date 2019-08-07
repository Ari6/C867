#include "student.h"

int Student::numInstance = 0;

Student::Student() {
  this->studentID = "";
  this->firstName = "Jane";
  this->lastName = "Doe";
  this->emailAddress = "";
  this->age = 0;
  for (int i = 0; i < 3; ++i) {
    this->daysInCourse[i] = 0;
  }
  this->degree = Degree::NA;
}

Student::~Student()
{
}

/*
    Setters
*/
void Student::setStudentID(std::string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress) {
  this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age; 
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
}

void Student::setDegree(Degree degree) {
	this->degree = degree;
}
 /*
    Getters
 */
std::string Student::getStudentID() { return this->studentID; }

std::string Student::getFirstName() { return this->firstName; }

std::string Student::getLastName() { return this->lastName; }

std::string Student::getEmailAddress() { return this->emailAddress; }

int Student::getAge() { return this->age; }

int* Student::getDaysInCourse() { return this->daysInCourse; }

/*
    print
*/
void Student::print() {
  std::cout << this->getStudentID() << '\t';
    std::cout << "First Name: " << this->getFirstName() << '\t';
    std::cout << "Last Name: " << this->getLastName() << '\t';
    std::cout << "Age: " << this->getAge() << '\t';
    
    int* ret = nullptr;
    ret = this->getDaysInCourse();

    std::cout << "daysInCourse: {";
    for (int i = 0; i < 3; ++i) {
      if (i != 2) {
        std::cout << *(ret+i) << ", ";
      } else {
        std::cout << *(ret+i) << "} ";
      }
    }
}
