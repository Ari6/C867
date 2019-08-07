#include "softwareStudent.h"



SoftwareStudent::SoftwareStudent() : Student(){ 
    this->degree = Degree::SOFTWARE;
}


SoftwareStudent::~SoftwareStudent()
{
}

Degree SoftwareStudent::getDegreeProgram() { return this->degree; }
void SoftwareStudent::setDegree(Degree degree) {
	this->degree = degree;
}
void SoftwareStudent::print() {
    Student::print();
    std::cout << "Degree Program: Software" << std::endl;
}
