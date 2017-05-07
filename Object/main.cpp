#include <iostream>

using namespace std;

class Object{
public:
    Object(double weight)
    {
        this->weight = weight;
        cout<<"Constructing Object"<<endl;
    }
    double showweight(){return weight;}
    ~Object(){cout<<"Destructing Object"<<endl;}
private:
    double weight;
};

class Box:public Object{
public:
    Box(double weight,double height,double width):Object(weight)
    {

        this->height = height;
        this->width = width;
        cout<<"Constructing Box"<<endl;
    }
    double getheight(){return height;}
    double getwidth(){return width;}
    void show()
    {
        cout<<"weight:"<<Box::showweight()<<endl<<"height:"<<Box::getheight()<<endl<<"width:"<<Box::getwidth()<<endl;}
    ~Box(){cout<<"Destructing Box"<<endl;}
private:
    double height,width;
};
int main()
{
    Box Box1(100,23.5,25.6);
    Box1.show();
    return 0;
}
