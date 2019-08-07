#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"

class NetworkStudent : public Student {
public:
	NetworkStudent();
	virtual ~NetworkStudent();
    Degree getDegreeProgram();
    void setDegree(Degree degree);
    void print();
};
#endif
