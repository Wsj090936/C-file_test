#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "person.h"
class Student:public Person{
public:
    void initSmessage(string name,int age,string Sno,int Grade);
    string getSno();
    int getGrade();
    void showSmessage();
private:
    string Sno;
    int Grade;
};


#endif // STUDENT_H_INCLUDED
