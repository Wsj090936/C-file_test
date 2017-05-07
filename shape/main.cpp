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
    virtual void getArea() = 0;
    virtual void getPerim() = 0;
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
    void getArea()
    {
         double area;
        area = (Rectangle::getW()-Rectangle::getx())*(Rectangle::getH()-Rectangle::gety());
        cout<<"The area is:"<<area<<endl;
    }
    void getPerim()
    {
        cout<<"The perim is :"<<2*(Rectangle::getW()-Rectangle::getx())+2*(Rectangle::getH()-Rectangle::gety())<<endl;
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
    void getArea()
    {
        cout<<"The area is:"<<3.14*(pow(Circle::getA()-Circle::getx(),2)+pow(Circle::getB()-Circle::gety(),2))<<endl;
    }
    void getPerim()
    {

        cout<<"The perim is :"<<3.14*sqrt((pow(Circle::getA()-Circle::getx(),2)+pow(Circle::getB()-Circle::gety(),2)))<<endl;
    }
private:
    double A,B;
};
void fun(Shape *ptr)
{
    ptr->getArea();
}
void fun2(Shape *ptr)
{
    ptr->getPerim();
}
int main()
{
    Rectangle P;
    P.initRectangle(1,2,3,4);
    Circle B;
    B.initCircle(1,2,3,4);
    fun(&P);
    fun(&B);
    fun2(&P);
    fun2(&B);
    return 0;
}
