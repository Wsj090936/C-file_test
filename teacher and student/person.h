#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <string>
class Person{
public:
    void initmessage(string name,int age);
    void getname();
    void getage();
    void showmessage();
private:
    string name;
    int age;
};


#endif // PERSON_H_INCLUDED
