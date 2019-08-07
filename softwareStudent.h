#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"
class SoftwareStudent : public Student {
public:
	SoftwareStudent();
	virtual ~SoftwareStudent();
    Degree  getDegreeProgram();
    void setDegree(Degree degree);
    void print();
};
#endif
