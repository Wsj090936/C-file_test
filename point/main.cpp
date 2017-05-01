#include <iostream>
#include <math.h>
using namespace std;

class Point{
public:
    Point(double X1 = 0,double Y1 = 0)
    {
        X = X1;
        Y = Y1;
        cout<<"Use constructor"<<endl;
    }
    int getX()
    {
        return X;
    }
    int getY()
    {
        return Y;
    }
    ~Point()
    {
        cout<<"Desruvtor"<<endl;
    }
private:
    double X,Y;
};
void Set(Point *p)
{
    int a;
    double i,j;
    cout<<"Please input ten points :"<<endl;
    for(a = 0;a<10;a++)
     {
         cin>>i>>j;
         *p = Point(i,j);
         p += 1;
     }
}
void Display(Point *p)
{
    cout<<"The point is :"<<endl;
    int a;
    for(a = 0;a<10;a++)
    {
        cout<<"("<<p->getX()<<","<<p->getY()<<")"<<endl;
        p += 1;
    }
}
void Length(Point *p)
{
    int a;
    double sum = 0;
    Point *s;
    for(a = 0;a<9;a++)//������a<9��ԭ�����ڼ���10�����������ĳ���ʱ����pָ��ָ���9����ʱ��sָ�ڵ�10���㣬��ʱ�����Ѿ���ɡ�
    {
        s = p + 1;//����һ��ָ��ʼ��ָ����һ���㣻
        sum += sqrt(pow((p->getX()-s->getX()),2) + pow((p->getY()-s->getY()),2));
    }
    cout<<"The length is :"<<sum<<endl;
}
int main()
{

    Point *P = new Point [10];//��̬��������
    Set(P);
    Display(P);
    Length(P);
    delete[] P;//ɾ������
    return 0;
}
