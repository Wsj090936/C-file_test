#include<string>
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
using std::string;
class Person{
public:
    void initmessage(string name,int age);
    string getname();
    int getage();
    void showmessage();
private:
    string name;
    int age;
};
#endif // PERSON_H_INCLUDED
