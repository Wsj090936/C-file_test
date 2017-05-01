#include <iostream>
#include <string>
using namespace std;
class Student{
public:
    Student(string Sno = 0,int Grade = 0):x(Sno),y(Grade){}
    string getx(){return x;}
    int gety() {return y;}

private:
    string x;
    int y;
};
    void ShowMax(Student *p)
    {
        int i = 0,a = 0;
        Student *S;
        S = p;//定义纪录指针
        for(i = 0;i<5;i++)//利用i纪录成绩最大的学生的编号
        {
            if(p->gety()>=a)
            {
                a = p->gety();
                S = p;//当a的值发生改变的时候纪录指针指向所改变的对象的地址
            }
                p++;
        }
        cout<<"The max grade is:"<<a<<endl<<"The Sno is:"<<S->getx()<<endl;
    }
int main()
{
    Student S[5] = {Student("2015211840",88),Student("2015211841",94),Student("2015211842",75),Student("2015211843",85),Student("2015211844",92)};
    Student *ptr = S;
    ShowMax(ptr);
    return 0;
}
