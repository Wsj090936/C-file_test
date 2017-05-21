#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
template<class T>
class Node{
private:
    Node *next;
public:
    T data;
    Node(const T &data,Node<T> *next);
    void insertAfter(Node<T> *p);
    Node<T> *deleteAfter();
    Node<T> *nextNode();
    const Node<T> *nextNode() const;
};
template<class T>
Node<T>::Node(const T &data,Node<T> *next):data(data),next(next){}
template<class T>
void Node<T>::insertAfter(Node<T> *p)
{
    p->next = next;
    next = p;
}
template<class T>
Node<T>*Node<T>::deleteAfter(){
    Node<T> tempPtr = next;
    if(next == 0)
        return 0;
    next = tempPtr->next;
    return tempPtr;
}
template<class T>
Node<T>*Node<T>::nextNode(){
    return next;
}
template<class T>
const Node<T>*Node<T>::nextNode()const{
    return next;
    }

#endif // NODE_H_INCLUDED
