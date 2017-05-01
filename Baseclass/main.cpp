#include <iostream>

using namespace std;
class BaseClass{
public:
    void fn1(){cout<<"BaseClass fn1"<<endl;}
    void fn2(){cout<<"BaseClass fn2"<<endl;}

};
class DerivedClass:public BaseClass{
public:
    void fn1(){cout<<"DerivedClass fn1"<<endl;}
    void fn2(){cout<<"DerivedClass fn2"<<endl;}
};

int main()
{
    BaseClass *BC;
    DerivedClass D,*DC;
    D.fn1();
    D.fn2();
    BC=DC=&D;
    BC->fn1();
    BC->fn2();
    DC->fn1();
    DC->fn2();
    cout << "Hello world!" << endl;
    return 0;
}
