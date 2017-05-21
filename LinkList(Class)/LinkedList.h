#include<iostream>
using namespace std;
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include"Node.h"
template<class T>
class LinkedList{
private:
    Node<T> *Front,*Rear;//��ͷָ�����βָ��
    Node<T> *prevPtr,*currPtr;//��ǰ����λ��,����ָ��ǰ��㣬ǰ��ָ��ǰ����ǰһ���
    int Size;//�����е�Ԫ�ظ���
    int position;//��ǰԪ���ڱ��е�λ�ã��α꣩
    Node<T> *newNode(const T &item,Node<T> *ptrNext = NULL);//itemΪ������*ptrNextΪָ����
    void freeNode(Node<T> *p);
    void Copy(const LinkedList<T> &L);//������L���Ƶ���ǰ����
public:
    LinkedList();
    LinkedList(const LinkedList<T> &L);
    ~LinkedList();
    LinkedList<T> &operator=(const LinkedList<T>&L);
    int getsize()const;//���������е�Ԫ�ظ���
    bool isEmpty() const;//�ж������Ƿ�Ϊ��
    void reset(int pos = 0);//��ʼ���α��λ��
    void next();//�α��ƶ�����һ��λ��
    bool endOfList() const;//�ж��α��Ƿ��������β��λ��
    int CurrentPosition() const;
    void insertFront(const T &item);//�ڱ�ͷ������
    void insertRear(const T &item);//�ڱ�β��������
    void insertAt(const T &item);//�ڵ�ǰ���֮ǰ������
    void insertAfter(const T &item);//�ڵ�ǰ���֮�������
    T deleteFront();//ɾ��ͷ���
    void deleteCurrent();//ɾ����ǰ���
    T &data();//���ضԵ�ǰ����Ա���ݵ�����
    const T &data()const;//���ضԵ�ǰ����Ա���ݵĳ�����
    void Clear();//�������
};
template<class T>
Node<T> *LinkedList<T>::newNode(const T &item,Node<T> *ptrNext)
{
    Node<T> *newNode;
    newNode = new Node<T>(item,ptrNext);
    if(newNode == NULL)//�ж��Ƿ񴴽��ɹ�
        cout<<"Create fail"<<endl;
    return newNode;
}
template<class T>
void LinkedList<T>::freeNode(Node<T> *p)
{
    delete p;
}
template<class T>
void LinkedList<T>::Copy(const LinkedList<T> &L)
{
    if(L.Size == 0)
        return;
    Front=Rear=newNode(L.Front->data);//����ǰ�ڵ��ͷָ���βָ�붼ָ���һ���ڵ�
    for(Node<T> *srcNode = L.Front->nextNode();srcNode!=NULL;)//��ʼ���е�һ���ڵ�֮��ĸ���
    {
        Node<T> *newNode = newNode(srcNode->data);//����һ�δ���Ľڵ��next�ڵ㸳ֵ��һ����Node<T>���͵�ָ��
        Rear->insertAfter(newNode);//����β�巨�����½ڵ�
        Rear = newNode;//�ı�βָ���ָ��
        srcNode = srcNode->nextNode();//ѭ����ɺ�ָ��ָ����һ�����
    }
    Size = L.Size;//���������������Ĵ�С����ͬ��
    Reset(position = L.CurrentPosition());//�����α�
}
template<class T>
LinkedList<T>::LinkedList():Front(NULL),Rear(NULL),prevPtr(NULL),Size(0),position(0){}//�޲εĹ��캯����ʼ��
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &L): Front(NULL),Rear(NULL),prevPtr(NULL),currPtr(NULL),Size(0),position(0)
{
    Copy(L);//��������
}
template<class T>
LinkedList<T>::~LinkedList()
{
    Clear();
}
template<class T>
LinkedList<T>&LinkedList<T>::operator=(const LinkedList<T>&L)
{
    Clear();
    Copy(L);
    return *this;
}
template<class T>
int LinkedList<T>::getsize() const
{
    return Size;
}
template<class T>
bool LinkedList<T>::isEmpty() const
{
    return (Size==0);
}
template<class T>
void LinkedList<T>::reset(int pos)
{
    if(0<=pos&&pos<=Size)//�ж��α�λ���Ƿ�λ��0��Size֮��
    {
        position = 0;
        prevPtr = NULL;
        currPtr = Front;
        while(pos--)//�α�ص�ͷ�ڵ㣬����ǰ��
        next();

    }
    else{
        position = pos;
        prevPtr = NULL;
        currPtr = NULL;
    }
    }
template <class T>
void LinkedList<T>::next()
{
    position++;
    prevPtr = currPtr;
    if(currPtr!=NULL)
        currPtr = currPtr->nextNode();
}
template<class T>
bool LinkedList<T>::endOfList()const
{
    return (currPtr == NULL);//�ж��α��Ƿ�β������������ֵ
}
template <class T>
int LinkedList<T>::CurrentPosition() const
{
    return position;
}
template<class T>
void LinkedList<T>::insertFront(const T &item)//��ͷ������
{
    Front = newNode(item,Front);
    if(isEmpty())//�ж������Ƿ�Ϊ��
    {
        Rear = Front;//��ͷ�ͱ�βָ��ͬһλ��
        Size++;
        reset(++position);
    }
}
template<class T>
void LinkedList<T>::insertRear(const T &item)
{
    Node<T> *newNode = newNode(item);
    if(isEmpty())
    {
        Front = Rear = newNode;
    }
    else{
        Rear->insertAfter(newNode);
        Rear = newNode;
    }
    Size++;
    reset(position);
}
template<class T>
void LinkedList<T>::insertAt(const T &item)//�ڵ�ǰ���֮ǰ����
{
    if(currPtr!=NULL)
        Node<T> *newNode = newNode(item,currPtr);
    if(prevPtr!=NULL)
        prevPtr->insertAfter(newNode);
    else{
        Front = prevPtr = newNode;
        Size++;
        reset(++position);
    }
}
template<class T>
void LinkedList<T>::insertAfter(const T &item)
{
    if(currPtr!=NULL)
        {
        Node<T>*newNode=newNode(item,currPtr->nextNode());
        currPtr->InsertAfter(newNode);
        if(Rear==currPtr)
        Rear=newNode;
        Size++;
        }
}
template <class T>
T LinkedList<T>::deleteFront()
{
    if(isEmpty())
    {
        cout<<"Already empty"<<endl;
    }
    else{//ִ�������ɾ������
        Node<T> *delNode = Front;
        Front = Front->nextNode();
        if(--Size == 0)
        {
            Rear = NULL;
        }
        reset(--position);
        T item = delNode->data;
        freeNode(delNode);
        return item;
    }
}
template<class T>
void LinkedList<T>::deleteCurrent()
{
    if(currPtr!=NULL)
    {
        if(Front == currPtr)//�����ǰ���Ϊ��ͷ�Ļ����ñ�ͷָ����һ���
            Front = currPtr->nextNode();
        if(Rear == currPtr)//�����ǰ���Ϊ��β�Ļ����ñ�β��ָ��prevPtr
            Rear = prevPtr;
        if(prevPtr!=NULL)
            prevPtr->deleteAfter();//ɾ����ǰ���
        freeNode(currPtr);
        Size--;
        reset(position);
    }
}
template<class T>
T &LinkedList<T>::data()
{
    if(currPtr==NULL)
    {
        cout<<"It is temp"<<endl;
        return NULL;
    }
    return currPtr->data;
}
template<class T>
const T&LinkedList<T>::data()const
{
    if(currPtr==NULL)
    {
        cout<<"It is temp"<<endl;
        return NULL;
    }
    return currPtr->data;
}
template <class T>
void LinkedList<T>::Clear()
{
    while(!isEmpty())
        deleteFront();
}
#endif // LINKEDLIST_H_INCLUDED
