#include <iostream>
using namespace std;
class Car;
class Boat{
public:
    Boat(float W):weight(W){}
    int getweight()
    {
        return weight;
    }
    friend float getTotalWeight(Boat &p1,Car &p2);
private:
    float weight;
};
class Car{
public:
    Car(float C)
    {
        weight = C;
    }
    int getweight()
    {
        return weight;
    }
    friend float getTotalWeight(Boat &p1,Car &p2);
private:
    float weight;
};
float getTotalWeight(Boat &p1,Car &p2)
{
    float TotalWeight = p1.weight + p2.weight;
    return TotalWeight;
}
int main()
{
    Boat p1(5);
    Car p2(6);
    cout << "The boat's weight is :" <<p1.getweight()<< endl<<"The car's weight is :"<<p2.getweight()<<endl;
    cout <<"The totalweight is :"<<getTotalWeight(p1,p2)<<endl;
    return 0;
}
