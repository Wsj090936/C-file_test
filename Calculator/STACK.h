#include<assert.h>
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
template<class T,int SIZE = 50>
class Stack{
private:
    T list[SIZE];
    int Top;
public:
    Stack();
    void push(T item);
    T pop();
    void Clear();
    T peek();
    bool isEmpty();
    bool isFull();
};
template<class T,int SIZE>
Stack<T,SIZE>::Stack(){Top = -1;}
template<class T,int SIZE>
void Stack<T,SIZE>::push(T item)
{
    assert(!isFull());
    list[++Top] = item;
}
template<class T,int SIZE>
T Stack<T,SIZE>::pop()
{
    assert(!isEmpty());
    return list[Top--];
}
template<class T,int SIZE>
T Stack<T,SIZE>::peek()
{
    assert(!isEmpty());
    return list[Top];
}
template<class T,int SIZE>
bool Stack<T,SIZE>::isEmpty()
{
    return Top == -1;
}
template<class T,int SIZE>
bool Stack<T,SIZE>::isFull()
{
    return Top == SIZE-1;
}
template<class T,int SIZE>
void Stack<T,SIZE>::Clear()
{
    Top = -1;
}
#endif // STACK_H_INCLUDED
