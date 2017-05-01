#include "student.h"
#include<iostream>
using namespace std;
    void Student::initSmessage(string name,int age,string Sno,int Grade)
    {
        initmessage(name,age);
        cout<<"Please input the other information(Sno and Grade):"<<endl;
        cin>>Sno>>Grade;
        this->Sno = Sno;
        this->Grade = Grade;
    }
    string Student::getSno(){return Sno;}
    int Student::getGrade(){return Grade;}
    void Student::showSmessage()
    {
        Person::showmessage();
        cout<<"Sno:"<<Student::Sno<<endl<<"Grade:"<<Student::Grade<<endl;
    }
