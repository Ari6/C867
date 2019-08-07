#include "securityStudent.h"



SecurityStudent::SecurityStudent(): Student() { 
    this->degree = Degree::SECURITY;
}


SecurityStudent::~SecurityStudent()
{
}

Degree SecurityStudent::getDegreeProgram() { return this->degree; }

void SecurityStudent::setDegree(Degree degree) {
	this->degree = degree;
}

void SecurityStudent::print() {
  Student::print();
  std::cout << "Degree Program: Security" << std::endl;
}
