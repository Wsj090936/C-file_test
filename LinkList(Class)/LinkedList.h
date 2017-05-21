#include<iostream>
using namespace std;
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include"Node.h"
template<class T>
class LinkedList{
private:
    Node<T> *Front,*Rear;//表头指针与表尾指针
    Node<T> *prevPtr,*currPtr;//当前遍历位置,后者指向当前结点，前者指向当前结点的前一结点
    int Size;//链表中的元素个数
    int position;//当前元素在表中的位置（游标）
    Node<T> *newNode(const T &item,Node<T> *ptrNext = NULL);//item为数据域，*ptrNext为指针域
    void freeNode(Node<T> *p);
    void Copy(const LinkedList<T> &L);//将链表L复制到当前表中
public:
    LinkedList();
    LinkedList(const LinkedList<T> &L);
    ~LinkedList();
    LinkedList<T> &operator=(const LinkedList<T>&L);
    int getsize()const;//返回链表中的元素个数
    bool isEmpty() const;//判断链表是否为空
    void reset(int pos = 0);//初始化游标的位置
    void next();//游标移动到下一个位置
    bool endOfList() const;//判断游标是否到了链表的尾部位置
    int CurrentPosition() const;
    void insertFront(const T &item);//在表头插入结点
    void insertRear(const T &item);//在表尾部插入结点
    void insertAt(const T &item);//在当前结点之前插入结点
    void insertAfter(const T &item);//在当前结点之后插入结点
    T deleteFront();//删除头结点
    void deleteCurrent();//删除当前结点
    T &data();//返回对当前结点成员数据的引用
    const T &data()const;//返回对当前结点成员数据的常引用
    void Clear();//清空链表
};
template<class T>
Node<T> *LinkedList<T>::newNode(const T &item,Node<T> *ptrNext)
{
    Node<T> *newNode;
    newNode = new Node<T>(item,ptrNext);
    if(newNode == NULL)//判断是否创建成功
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
    Front=Rear=newNode(L.Front->data);//将当前节点的头指针和尾指针都指向第一个节点
    for(Node<T> *srcNode = L.Front->nextNode();srcNode!=NULL;)//开始进行第一个节点之后的复制
    {
        Node<T> *newNode = newNode(srcNode->data);//将上一次存入的节点的next节点赋值给一个新Node<T>类型的指针
        Rear->insertAfter(newNode);//利用尾插法插入新节点
        Rear = newNode;//改变尾指针的指向
        srcNode = srcNode->nextNode();//循环完成后指针指向下一个结点
    }
    Size = L.Size;//复制完后两个链表的大小世相同的
    Reset(position = L.CurrentPosition());//重置游标
}
template<class T>
LinkedList<T>::LinkedList():Front(NULL),Rear(NULL),prevPtr(NULL),Size(0),position(0){}//无参的构造函数初始化
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &L): Front(NULL),Rear(NULL),prevPtr(NULL),currPtr(NULL),Size(0),position(0)
{
    Copy(L);//复制链表
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
    if(0<=pos&&pos<=Size)//判断游标位置是否位于0和Size之间
    {
        position = 0;
        prevPtr = NULL;
        currPtr = Front;
        while(pos--)//游标回到头节点，逐步向前移
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
    return (currPtr == NULL);//判断游标是否到尾部，并返回真值
}
template <class T>
int LinkedList<T>::CurrentPosition() const
{
    return position;
}
template<class T>
void LinkedList<T>::insertFront(const T &item)//表头插入结点
{
    Front = newNode(item,Front);
    if(isEmpty())//判断链表是否为空
    {
        Rear = Front;//表头和表尾指向同一位置
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
void LinkedList<T>::insertAt(const T &item)//在当前结点之前插入
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
    else{//执行链表的删除操作
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
        if(Front == currPtr)//如果当前结点为表头的话就让表头指向下一结点
            Front = currPtr->nextNode();
        if(Rear == currPtr)//如果当前结点为表尾的话就让表尾部指向prevPtr
            Rear = prevPtr;
        if(prevPtr!=NULL)
            prevPtr->deleteAfter();//删除当前结点
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
