#include"person.h"
#include<iostream>
#include<string>
using namespace std;
    void Person::initmessage(string name,int age)
    {
        cout<<"Please input the message:"<<endl;
        cin>>name>>age;
        this->name = name;
        this->age = age;
    }
    string Person::getname(){return name;}
    int Person::getage(){return age;}
    void Person::showmessage()
    {
        cout<<"name:"<<Person::getname()<<endl<<"age:"<<Person::getage()<<endl;
    }
