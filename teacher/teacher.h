#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED
#include "person.h"
class Teacher:public Person{
public:
    void initTmessage(string name,int age,string Tno,string duty);
    string getTno();
    string getduty();
    void showTmessage();

private:
    string Tno,Department,duty;
};
#endif // TEACHER_H_INCLUDED
