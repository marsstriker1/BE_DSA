#include <iostream>
using namespace std;
template <class t>
class Node
{
public:
    t item;
    Node<t>* next;
};
template <class t>
class List
{

    int sizeL;
    int maxSize;
    Node<t>* start;
public:
    //int maxSize;
    class UNDERFLOW{};
    class OVERFLOW{};
    List(int s=5):maxSize(s)
    {
        sizeL=0;
        start=nullptr;
    }
    ~List()
    {
        if(start!=nullptr)
        {
            Node<t>* p =start;
            Node<t>* q = p->next;
            if(q==nullptr)
                delete p;
            else
            for(;q!=nullptr;p=q,q=q->next)
                delete p;
        }
    }
    int sizeG()
    {
        return sizeL;
    }
    void setMax(int s)
    {
       maxSize=s;
    }
    t peekFront()
    {
        if(start==nullptr)
        {
            throw UNDERFLOW();
        }
        return start->item;
    }
    void insertAtFront(t);
    void insertAtEnd(t);
    t removeFromFront();
    void display();
};
template <class t>
void List<t>::insertAtFront(t data)
{
    if(sizeL<maxSize)
    {
        sizeL++;
        Node<t>* newNode = new Node<t>();
        newNode->item=data;
        if(start==nullptr)
        {
            newNode->next=nullptr;
            start=newNode;
        }
        else
        {
            newNode->next=start;
            start=newNode;
        }
    }
    else
    {
        throw OVERFLOW{};
    }

}
template<class t>
void List<t>::insertAtEnd(t _item)
{
    if(sizeL<maxSize)
    {
        sizeL++;
        Node<t>* newNode = new Node<t>();
        newNode->item = _item;
        newNode->next = nullptr;
        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            Node<t>* p = start;
            Node<t>* q = p->next;
                for(; q != nullptr ; p = q , q = p->next) ;
            p->next = newNode;
        }
    }
    else
    {
        throw OVERFLOW{};
    }
}
template <class t>
t List<t>::removeFromFront()
{
    if(start==nullptr)
        throw UNDERFLOW();
    sizeL--;
    t temp=start->item;
    start=start->next;
    return temp;
}
template <class t>
void List<t>::display()
{
    if(start == nullptr)
        throw UNDERFLOW();
    Node<t>* p = start;
    for(; p != nullptr ; p = p->next)
        std::cout<<" "<<p->item;
}
