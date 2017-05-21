#include <iostream>
using namespace std;
class Motor{
public:
    Motor(int Nom,int NoT,double rate,string ProFactory,string Own)
    {
        this->NoM = Nom;
        this->NoT = NoT;
        this->rate = rate;
        this->ProFactory = ProFactory;
        this->Own = Own;
    }
    virtual void display()
    {
        cout<<"This is a Motor,the information about it is:"<<endl;
        cout<<"No of man:"<<Motor::getNom()<<endl<<"No of whool:"<<Motor::getNot()
        <<endl<<"Rate:"<<Motor::getRate()<<endl<<"ProFactory:"<<Motor::getPro()<<endl<<"Own"<<Motor::getOwn()<<endl;
    }
    int getNom(){return NoM;}
    int getNot(){return NoT;}
    double getRate(){return rate;}
    string getPro(){return ProFactory;}
    string getOwn(){return Own;}
private:
    int NoM,NoT;
    double rate;
    string ProFactory,Own;
};
class Car:public Motor{
public:
    Car(int Nom,int NoT,double rate,string ProFactory,string Own):Motor(Nom,NoT,rate,ProFactory,Own){}
    void display()
    {
        cout<<"This is a Car,the information about it is:"<<endl;
        cout<<"No of man:"<<Car::getNom()<<endl<<"No of whool:"<<Car::getNot()
        <<endl<<"Rate:"<<Car::getRate()<<endl<<"ProFactory:"<<Car::getPro()<<endl<<"Own:"<<Car::getOwn()<<endl;
    }
};
class Bus:public Motor{
public:
    Bus(int Nom,int NoT,double rate,string ProFactory,string Own):Motor(Nom,NoT,rate,ProFactory,Own){}
    void display()
    {
        cout<<"This is a Bus,the information about it is:"<<endl;
        cout<<"No of man:"<<Bus::getNom()<<endl<<"No of whool:"<<Bus::getNot()
        <<endl<<"Rate:"<<Bus::getRate()<<endl<<"ProFactory:"<<Bus::getPro()<<endl<<"Own:"<<Bus::getOwn()<<endl;
    }
};
class Truck:public Motor{
public:
    Truck(int Nom,int NoT,double rate,string ProFactory,string Own):Motor(Nom,NoT,rate,ProFactory,Own){}
    void display()
    {
        cout<<"This is a Truck,the information about it is:"<<endl;
        cout<<"No of man:"<<Truck::getNom()<<endl<<"No of whool:"<<Truck::getNot()
        <<endl<<"Rate:"<<Truck::getRate()<<endl<<"ProFactory:"<<Truck::getPro()<<endl<<"Own:"<<Truck::getOwn()<<endl;
    }
};
void fun(Motor *ptr)
{
    ptr->display();
}
int main()
{
    Car C(4,4,500,"Dazhong","wushijia");
    Bus B(30,8,2000,"Bench","Tom");
    Truck T(12,6,2500,"WestenTruck","Tony");
    fun(&C);
    fun(&B);
    fun(&T);
    return 0;
}
