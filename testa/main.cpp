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
        S = p;//�����¼ָ��
        for(i = 0;i<5;i++)//����i��¼�ɼ�����ѧ���ı��
        {
            if(p->gety()>=a)
            {
                a = p->gety();
                S = p;//��a��ֵ�����ı��ʱ���¼ָ��ָ�����ı�Ķ���ĵ�ַ
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
