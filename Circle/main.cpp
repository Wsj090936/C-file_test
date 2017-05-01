#include <iostream>

using namespace std;

class Circle{
public:
    Circle(double x)
    {
        radius = x;
    }
    double getArea()
    {
        return radius*radius*3.14;
    }

private:
    double radius;
};

int main()
{
    double x;
    cout<<"Please input the radius:"<<endl;
    cin>>x;
    Circle R(x);
    cout << "The area is :" <<R.getArea()<< endl;
    return 0;
}
