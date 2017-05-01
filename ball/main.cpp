#include <iostream>
#include <math.h>
using namespace std;
class Circle{
public:
    void initRadius(double R)
    {
        Radius = R;
    }
protected:
    double Radius;
};
class Ball:public Circle{
public:
    void initBall(double R)
    {
        initRadius(R);
    }
    double getVolume()
    {
        double Volume = 3.14*pow(Radius,3)*4/3;
        return Volume;
    }
    double getArea()
    {
        double Area = 4*3.14*pow(Radius,2);
        return Area;
    }
    void show(Ball p)
    {
        cout<<"The Volume is:"<<p.getVolume()<<endl<<"The Area is:"<<p.getArea()<<endl;
    }
};
class Cylindrical:public Ball{
public:
    void initCylindrical(double R,double High)
    {
        initRadius(R);
        this->High = High;
    }
    double getVolume()
    {
        double Volume = 3.14*Radius*High;
        return Volume;
    }
    double getArea()
    {

        double Area = 2*3.14*Radius+3.14*2*Radius*High;
        return Area;
    }
    void show(Cylindrical p)
    {
        cout<<"The Volume is:"<<p.getVolume()<<endl<<"The Area is:"<<p.getArea()<<endl;
    }
protected:
    double High;
};
class Cone:public Cylindrical{
public:
        void initCone(double R,double High)
    {
        initCylindrical(R,High);
    }

    double getArea()
    {
        double Area = sqrt(pow(Radius,2)+pow(High,2))*3.14*Radius + 3.14*pow(Radius,2);
        return Area;
    }
    void show(Cone p)
    {
        cout<<"The Volume is:"<<(double)1/3*p.getVolume()<<endl<<"The Area is:"<<p.getArea()<<endl;
    }
};
int main()
{
    Ball ball;
    Cylindrical CY;
    Cone cone;
    ball.initBall(1);
    ball.show(ball);
    CY.initCylindrical(1,1);
    CY.show(CY);
    cone.initCone(1,1);
    cone.show(cone);
    return 0;
}
