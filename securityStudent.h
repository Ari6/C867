#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"
class SecurityStudent : public Student {
 public:
    SecurityStudent();
    virtual ~SecurityStudent();
    Degree getDegreeProgram();
    void setDegree(Degree degree);
    void print();

};

#endif
