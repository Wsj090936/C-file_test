#include <iostream>

using namespace std;
template<typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>(int data, Node<T>* next):data(data),next(next){}

};
template<class T>
class LinkedList{
public:
    int Size = 0;
    Node<T> *Front=0,*Rear=0;;
    void insert(LinkedList L,LinkedList L1)//表示被插入链表，L1表示插入链表
    {
        Node<T> *p,*s,*temp;
        p=L->Rear;
        s=L1->Front;
        for(int i = 1;i<L1.Size;i++)
        {
            temp = s->data;
            p->next = temp;
            p = temp;
            temp = temp->next;
        }
    }
    void Print()
    {
        int i = 0;
        Node<T> *p = Front;
        for(;i<Size;i++)
        {
            cout<<p->data<<" ";
        }

    }
    void create(int item)
    {
            if(Front==0&&Rear==0)
           {

            Node<T> *newNode;
            newNode = new Node<T>(item,0);
            Front = newNode;
            Rear = newNode;
           }
           else
           {
               Node<T> *newNode=new Node<T>(item,0);
               Rear->next=newNode;
               Rear = newNode;
           }
           Size++;

}
};
int main()
{

    LinkedList<int> L;
        L.create(1);
        L.create(2);
        L.create(3);
        L.create(4);
        L.create(5);
        cout<<"The linklist one's data is:"<<endl;
    L.Print();
    LinkedList<int> M;
    for(int i =0;i<5;i++)
    {
        int item;
        cin>>item;
        M.create(item);
    }
        cout<<"The linklist two's data is:"<<endl;
        M.Print();

}
