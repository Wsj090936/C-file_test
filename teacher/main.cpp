#include <iostream>
#include<string>
#include"teacher.h"
#include"student.h"
using namespace std;

int main()
{
    Teacher tea;
    Student stu;
    stu.initSmessage("null",0,"null",0);
    stu.showSmessage();
    tea.initTmessage("null",0,"null","null");
    tea.showTmessage();
    return 0;
}
