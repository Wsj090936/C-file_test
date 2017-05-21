#include <iostream>
using namespace std;
class Teacher{
public:
    Teacher(double BaseSalary=500,double Benf = 0,double Time = 0,double Hours = 0)
    {
        this->Time = Time;
        this->Hours = Hours;
        this->BaseSalary = BaseSalary;
        this->Benf = Benf;
    }
    virtual void display()
    {
        cout<<"This is a teacher,his salary is"<<Teacher::getSalary()<<"yuan"<<endl;
    }
    double getSalary(){return BaseSalary;}
    double getBenf(){return Benf;}
    double getHours(){return Hours;}
    double getTime(){return Time;}
private:
    double BaseSalary,Time,Hours;
    double Benf;
};
class Lecturer:public Teacher{
public:

    Lecturer(double BaseSalary,double Benf,double Time,double Hours):Teacher(BaseSalary,Benf,Time,Hours){}

    void display()
    {

        cout<<"This is a Lecturer,his salary is :"<<(Lecturer::getSalary()+Lecturer::getBenf()+Lecturer::getHours()*Lecturer::getTime())<<"yuan"<<endl;
    }
};
class Aprofessor:public Teacher{
public:
    Aprofessor(double BaseSalary,double Benf,double Time,double Hours):Teacher(BaseSalary,Benf,Time,Hours){}

    void display()
    {

        cout<<"This is a Aprofessor,his salary is :"<<(Aprofessor::getSalary()+Aprofessor::getBenf()+Aprofessor::getHours()*Aprofessor::getTime())<<"yuan"<<endl;
    }
};
class Professor:public Teacher{
public:
    Professor(double BaseSalary,double Benf,double Time,double Hours):Teacher(BaseSalary,Benf,Time,Hours){}
    void display()
    {

        cout<<"This is a Professor,his salary is :"<<(Professor::getSalary()+Professor::getBenf()+Professor::getHours()*Professor::getTime())<<"yuan"<<endl;
    }
};
void fun(Teacher *ptr)
{
    ptr->display();
}
int main()
{
    Lecturer L(800,1300,80,40);
    Aprofessor A(900,1800,65,45);
    Professor P(1000,2300,60,50);
    fun(&L);
    fun(&A);
    fun(&P);
    return 0;
}
