#include <iostream>

using namespace std;
class BaseClass{
public:
    virtual ~BaseClass();
};
BaseClass::~BaseClass(){
cout<<"Base destructor"<<endl;
}
class DerivedClass:public BaseClass{
public:
    DerivedClass(){p = new int(1);}
    ~DerivedClass()
    {
        cout<<"Derived destructor"<<endl;
        delete p;
    }
private:
    int *p;
};
void fun(BaseClass *ptr)
{
    delete ptr;
}
int main()
{
    BaseClass* A = new DerivedClass();
    fun(A);

    cout << "Hello world!" << endl;
    return 0;
}
