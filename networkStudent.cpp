#include "networkStudent.h"


NetworkStudent::NetworkStudent(): Student() {
    this->degree = Degree::NETWORK;
}


NetworkStudent::~NetworkStudent()
{
}

Degree NetworkStudent::getDegreeProgram() { return this->degree; }

void NetworkStudent::setDegree(Degree degree) {
	this->degree = degree;
}
void NetworkStudent::print() {
  Student::print();
  std::cout << "Degree Program: Network" << std::endl;
}
