#include <iostream>
#include<math.h>

using namespace std;

class Shape{
public:
    void initpoint(double x,double y)
    {
        this->x = x;
        this->y = y;
    }
    double getx(){return x;}
    double gety(){return y;}
private:
    double x,y;
};

class Rectangle:public Shape{
public:
    void initRectangle(double x,double y,double W,double H)
    {
        initpoint(x,y);
        this->H = H;
        this->W = W;
    }
    double getW(){return W;}
    double getH(){return H;}
    void getArea(Rectangle P)
    {
         double area;
        area = (P.getW()-P.getx())*(P.getH()-P.gety());
        cout<<"The area is:"<<area<<endl;
    }
private:
    double W,H;
};

class Circle:public Shape{
public:
    void initCircle(double x,double y,double A,double B)//A,B表示另一个点
    {
        initpoint(x,y);
        this->A = A;
        this->B = B;
    }
    double getA(){return A;}
    double getB(){return B;}
    void getArea(Circle P)
    {
        cout<<"The area is:"<<3.14*(pow(P.getA()-P.getx(),2)+pow(P.getB()-P.gety(),2))<<endl;
    }
private:
    double A,B;
};
class Square:public Rectangle{
public:
    void initSquare(double x = 0,double y = 0,double Q = 0,double E = 0)
    {
        while(true)
        {
            cout<<"Please input the point"<<endl;
            cin >>x>>y>>Q>>E;
            if(x-y != Q-E)
            cout<<"The point was error! Please input it again"<<endl;
            else
                {initRectangle(x,y,Q,E);
                break;}
        }//利用循环判断输入的点满不满足正方形的条件
    }

};
int main()
{
    Rectangle P;
    P.initRectangle(1,2,3,4);
    P.getArea(P);
    Circle B;
    B.initCircle(1,2,3,4);
    B.getArea(B);
    Square C;
    C.initSquare();
    C.getArea(C);
    cout << "Hello world!" << endl;
    return 0;
}
