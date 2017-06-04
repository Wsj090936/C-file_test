#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class CreateRandomNum  //Generate Random Number
{
public:
	void create();//Generate
	int RandomNum();//Random Number
private:
	int n;
};

class Run
{
public:
	void init();                    //��ʼ��
	void import();                   //����
	void show();                       //��ʾ
	void judge();                       //�ж�
 	void run(int t);                      //ִ��
private:
	CreateRandomNum a[4];
	int i,j,k,l,z[4];
	int num,grade;
	int n[25][4];
	char s[4];

};
void CreateRandomNum::create(){
    n = rand()%900+100;//�������100~900֮�����λ��
}
int CreateRandomNum::RandomNum(){
    return n;
}
void Run::init(){
	for(i=0;i<4;i++)
	{
		z[i]=0;
	}
	for(i=0;i<25;i++)
	{
		for(j=0;j<4;j++)
			n[i][j]=0;
	}
	k=0;
	i=0;
	j=0;
	grade=0;
	s[0]='\0';
}

void Run::import(){
    for(;;){//���������
        a[0].create();
        a[1].create();
        a[2].create();
        a[3].create();
        if(a[0].RandomNum()/100!=a[1].RandomNum()/100 && //��λ��ͬ
           a[1].RandomNum()/100!=a[2].RandomNum()/100 &&
           a[2].RandomNum()/100!=a[3].RandomNum()/100 &&
           a[0].RandomNum()/100!=a[2].RandomNum()/100 &&
           a[0].RandomNum()/100!=a[3].RandomNum()/100 &&
           a[1].RandomNum()/100!=a[3].RandomNum()/100){
        break;
        }
    }
    n[0][0] = a[0].RandomNum();
    n[0][1] = a[1].RandomNum();
    n[0][2] = a[2].RandomNum();
    n[0][3] = a[3].RandomNum();
}
void Run::show(){//��ʾ�����
	for(i=0;i<25;i++)
	{
		for(j=0;j<4;j++)
		{
			if(n[i][j]!=0)
			{
				cout<<n[i][j]<<"   ";
			}
			else
				cout<<"      ";
			if(_kbhit())//�������Ƿ�������
			{
			    s[k]=_getch();//��ȡ�����������
			    k++;
			}
		}
		cout<<endl;
	}
}
void Run::judge(){
   if(k==3)
	{
    	s[3]='\0';
		num=atoi(s);
		if(num==a[0].RandomNum() || num==a[1].RandomNum() || num==a[2].RandomNum() || num==a[3].RandomNum()) //����������������һ����ʾ������ͬ
		{
			grade += 10;
			cout<<"������10��Ŀǰ������"<<grade;
			if(num==a[0].RandomNum())//�������������x������ʾ������ͬ
			{
				for( ; ; )
				{
				a[0].create();
				if(a[0].RandomNum()/100!=a[1].RandomNum()/100 &&
                   a[0].RandomNum()/100!=a[2].RandomNum()/100 &&
                   a[0].RandomNum()/100!=a[3].RandomNum()/100)
					break;
				}
			    n[l-1-z[0]][0]=0;
			    z[0]=l-1;
			}
		    if(num==a[1].RandomNum())
			{
				for( ; ; )
				{
				a[1].create();
				if(a[0].RandomNum()/100!=a[1].RandomNum()/100 &&
                   a[1].RandomNum()/100!=a[2].RandomNum()/100 &&
                   a[1].RandomNum()/100!=a[3].RandomNum()/100)
					break;
				}
				n[l-1-z[1]] [1]=0;
			    z[1] = l - 1;
			}
			if(num==a[2].RandomNum())
			{
				for( ; ; )
				{
				a[2].create();
				if( a[2].RandomNum()/100!=a[1].RandomNum()/100 &&
                    a[0].RandomNum()/100!=a[2].RandomNum()/100 &&
                    a[2].RandomNum()/100!=a[3].RandomNum()/100)
					break;
				}
			    n[l-1-z[2]][2]=0;
			    z[2]=l-1;
			}
		    if(num==a[3].RandomNum())
			{
				for( ; ; )
				{
				a[3].create();
				if(a[3].RandomNum()/100!=a[1].RandomNum()/100 &&
                   a[3].RandomNum()/100!=a[2].RandomNum()/100 &&
                   a[0].RandomNum()/100!=a[3].RandomNum()/100)
					break;
				}
				n[l-1-z[3]][3]=0;
			    z[3]=l-1;
			}
		}
	    k=0;
		s[0]='\0';
	}
}
void Run::run(int i){
	for(l=1; ;l++)
	{
		show();
		judge();
		n[l-z[0]-1][0]=0;
		n[l-z[1]-1][1]=0;
		n[l-z[2]-1][2]=0;
		n[l-z[3]-1][3]=0;
        n[l-z[0]][0]=a[0].RandomNum();
		n[l-z[1]][1]=a[1].RandomNum();
        n[l-z[2]][2]=a[2].RandomNum();
		n[l-z[3]][3]=a[3].RandomNum();
        Sleep(i);
		system("cls");
	    if(l-z[0]==24 || l-z[1]==24 || l-z[2]==24 || l-z[3]==24)
		{
		    cout<<"�����ܵ÷֣�"<<grade<<endl;
			exit(0);
		}
	}
}
#endif // TYPE_H_INCLUDED

