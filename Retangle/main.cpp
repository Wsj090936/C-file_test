#include <iostream>

using namespace std;

class Retangle{
public:
    void getLen(unsigned short NewL,unsigned short NewW);
    void Area();
private:
    unsigned short X,Y;
};
void Retangle::getLen(unsigned short NewL,unsigned short NewW)
{
    X = NewL;
    Y = NewW;
}
void Retangle::Area()
{
    cout<<"The area is:"<<X*Y<<endl;
}
int main()
{
    Retangle retangle;
    unsigned short X,Y;
    cout << "Please input the length and width:" << endl;
    cin>>X>>Y;
    retangle.getLen(X,Y);
    retangle.Area();
    return 0;
}
