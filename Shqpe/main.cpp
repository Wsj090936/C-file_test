#include <iostream>

using namespace std;

class Employee{
public:
    Employee(char *Nname,char *Naddress,char *Ncity,char *Nno)
{
    name = Nname;
    address = Naddress;
    city = Ncity;
    no = Nno;
}
    void setname(char *Nname)
    {
        name = Nname;
    }
    void display()
    {
        cout<<"name:"<<name<<endl<<"Address:"<<address<<endl<<"City:"<<city<<endl<<"NO:"<<no<<endl;
    }
private:
    char *address,*city,*no;
    char *name;
};

int main()
{
    Employee X("wushijia","qinghai","xining","810600");
    X.display();
    X.setname("zuohuaiyue");
    X.display();
    return 0;
}
