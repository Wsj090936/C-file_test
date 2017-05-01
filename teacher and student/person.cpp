#include "person.h"
#include <iostream>
    void Person::initmessage(string name,int age)
    {
        cout<<"Please input the message:"<<endl;
        cin>>name>>age;
        this->name = name;
        this->age = age;
    }
    void Person::getname(){return name;}
    void Person::getage(){return age;}
    void Person::showmessage()
    {
        cout<<"name:"<<Person::getname()<<endl<<"age:"<<Person::getage()<<endl;
    }
