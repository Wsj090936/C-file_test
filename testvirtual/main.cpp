#include <iostream>

using namespace std;

class Person{
public:
    Person(){}
    Person(string Name,int age)
    {
        this->Name = Name;
        this->age = age;
    }
    string getname(){return Name;}
    int getage(){return age;}
    void show()
    {
        cout<<"Name:"<<Person::getname()<<endl<<"Age"<<Person::getage()<<endl;
    }
    string Name;
    int age;
};
class Leader:virtual public Person{
public:
    Leader(){}
    Leader(string Name,int age,string duty,string depart):Person(Name,age){
    this->duty = duty;
    this->depart = depart;
    }
    string getname(){return Person::getname();}
    int getage(){return Person::getage();}
    string getduty(){return duty;}
    string getdepart(){return depart;}
    void show1()
    {
        cout<<"Name:"<<Leader::getname()<<endl<<"Age:"<<Leader::getage()<<endl<<"Duty:"<<Leader::getduty()<<endl;
        cout<<"Department:"<<Leader::getdepart()<<endl;
    }
    string duty,depart;

};
class Engineer:virtual public Person{
public:
    Engineer(){}
    Engineer(string Name,int age,string major,string duty):Person(Name,age){
    this->major = major;
    this->duty = duty;
    }
    string getname(){return Person::getname();}
    int getage(){return Person::getage();}
    string getduty(){return duty;}
    string getmajor(){return major;}
    void show2()
    {
        cout<<"Name:"<<Engineer::getname()<<endl<<"Age:"<<Engineer::getage()<<endl<<"Duty:"<<Engineer::getduty()<<endl;
        cout<<"Major:"<<Engineer::getmajor()<<endl;
    }
    string major,duty;

};
class Chairman:public Leader,public Engineer{
public:

    void showLeader(Leader P)
    {
        P.show1();
    }
    void showEngineer(Engineer P)
    {
        P.show2();
    }


};
int main()
{
    Leader P("wushijia",18,"charge","information");
    Engineer Q("wuyuzhe",20,"programmer","software");
    Chairman B;
    B.showEngineer(Q);
    B.showLeader(P);
    return 0;
}
