#ifndef RUN_H_INCLUDED
#define RUN_H_INCLUDED
#include<ctype.h>
#include<iostream>
#include<stdlib.h>
#include"STACK.h"
using namespace std;
class Calculator{
private:
    Stack<double> s;
public:
    void run();
};
void Calculator::run()
{
    char c,prt[20];
    double d,e;//eΪ�ȳ�ջԪ��
    int i = 0;
    int a = 0;//���ָ���
    int x = 0;//���������
    char str[20];
    cout<<"please input the Mathematical expressions(input = to end)"<<endl;
    cin>>c;
    while(true)
    {
        while(isdigit(c)||c == '.')//�����ʽ�е�����ȫ������str��
        {
            str[i++] = c;
            str[i] = '\0';
            if(i>=10)
            {
                cout<<"too large!(0~9)"<<endl;

            }
            cin>>c;
            if(c=='*'||c=='/'||c=='+'||c=='-')
            {
                prt[x] = c;
                ++x;
                prt[x] = '\0';
                d=atof(str);//��char�͵��ַ�ת��Ϊdouble��
                s.push(d);
                i = 0;
                ++a;

            }else if(c == '=')
                {
                    d=atof(str);//��char�͵��ַ�ת��Ϊdouble��
                    s.push(d);
                    i = 0;
                    break;
                }
            }
            if(c!='=')
            cin>>c;
            else
                break;
        }
        for(int q = 0;q<x;q++ )
        { switch(prt[q])
            {
                case '+':
                    e = s.pop();
                    d = s.pop();
                    s.push(e+d);
                    break;
                case '-':
                    //double atr[10];
                    e = s.pop();
                    d = s.pop();
                    s.push(d-e);
                    break;
                case '*':
                    e = s.pop();
                    d = s.pop();
                    s.push(d*e);
                    break;
                case '/':
                    if(s.pop() == 0)
                    {
                        cout<<"Divided by 0!"<<endl;
                        s.Clear();
                    }else
                    {
                        e = s.pop();
                        d = s.pop();
                        s.push(d/e);
                    }

    }
        }
    cout<<"The result is:"<<s.pop()<<endl;
}
#endif // RUN_H_INCLUDED
