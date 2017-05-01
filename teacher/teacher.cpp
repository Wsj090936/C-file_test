#include "teacher.h"
#include<iostream>
using namespace std;
    void Teacher::initTmessage(string name = "null",int age = 0,string Tno = "null",string duty = "")
    {
        initmessage(name,age);
        cout<<"Please input other message(Tno and duty):"<<endl;
        cin>>Tno>>duty;
        this->Tno = Tno;
        this->duty = duty;
    }
    string Teacher::getTno(){return Tno;}
    string Teacher::getduty(){return duty;}
    void Teacher::showTmessage()
    {
        Person::showmessage();
        cout<<"Tno:"<<Teacher::getTno()<<endl<<"duty:"<<Teacher::getduty()<<endl;
    }
