#include <iostream>

using namespace std;

class Complex{
public:
    Complex(double xx = 0,double yy = 0){
        x = xx;
        y = yy;
 }
    double getx()
    {
        return x;
    }
    double gety()
    {
        return y;
    }
    void add(Complex p)
    {
        x = x+p.getx();
        y = y+p.gety();
    }
    void show()
    {
        if(y>0)
            cout<<"The resule is :"<<x<<"+"<<y<<"i"<<endl;
        else
            cout<<"The result is:"<<x<<y<<"i"<<endl;//当y为负数时改为有符号输出
    }
private:
    double x,y;
};

int main()
{
    Complex c1(3,5);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();
    return 0;
}
