#include <iostream>
using namespace std;
class Cats{
public:
    Cats(int xx = 0,int yy = 0):x(xx),y(yy)
    {
        numOfCats += x + y;
    }
    Cats(Cats &p)
    {
        x = p.x;
        y = p.y;
        numOfCats += x + y;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    static void getnumOfCats()
    {
        cout<<"The num of cats is:"<<numOfCats<<endl;
    }
private:
    int x,y;
    static int numOfCats;
};
int Cats::numOfCats = 0;
int main()
{
    Cats c(4,5);
    Cats::getnumOfCats();
    Cats D(c);
    Cats::getnumOfCats();
    return 0;
}
