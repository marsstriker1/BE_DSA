#include <iostream>
using namespace std;
template <class t>
struct NODE
{
    t item;
    NODE<t>* next;
};
template <class t>
class QueueL
{
    typedef NODE<t> Node;
    int sizeL;
    const int maxSize;
    Node* start;
public:
    class UNDERFLOW{};
    class OVERFLOW{};
    QueueL(int s=5):maxSize(s)
    {
        sizeL=0;
        start=nullptr;
    }
    ~QueueL()
    {
        if(start!=nullptr)
        {
            Node* p =start;
            Node* q = p->next;
            if(q==nullptr)
                delete p;
            else
            for(;q!=nullptr;p=q,q=q->next)
                delete p;
        }
    }
    int getSize()
    {
        return sizeL;
    }
    void enqueue(t);
    t dequeue();
    void display();
};
template <class t>
void QueueL<t>::enqueue(t data)
{
    if(sizeL<maxSize)
    {
        sizeL++;
        Node* newNode = new Node();
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
template <class t>
t QueueL<t>::dequeue()
{
    if(start == nullptr)
            throw UNDERFLOW();
    sizeL--;
        t temp;
        Node* p = start;
        Node* q = nullptr;
            for(;p->next != nullptr; q = p, p = p->next) ;
        if(q == nullptr)
        {
            start = nullptr;
        }
        else
        {
            q->next = nullptr;
        }
        temp = p->item;
        delete p;
        return  temp;
}
template <class t>
void QueueL<t>::display()
{
    if(start == nullptr)
        throw UNDERFLOW();
    Node* p = start;
    for(; p != nullptr ; p = p->next)
        std::cout<<" "<<p->item;
}
int main()
{
    int op,sizeSt,num;
    cout<<"Size of Queue:";
    cin>>num;
    sizeSt=num;
    QueueL<int> s(num);
    while(1)
    {
    try
    {
        cout<<"\nEnter Operation:\t1)Enqueue\t2)Dequeue\t3)Exit:";
        cin>>op;
        if(op==1)
        {
            if(s.getSize()<sizeSt)
            {
                cout<<"\nEnter number to be enqueued:";
                cin>>num;
                s.enqueue(num);
                cout<<"\nData in Queue:\t";
                s.display();
            }
            else
            {
                throw(QueueL<int>::OVERFLOW());
            }
        }
        else if(op==2)
        {
            s.dequeue();
            cout<<"\nData in Queue:\t";
            s.display();
        }
        else
        {
           exit(0);
        }
    }

    catch(QueueL<int>::UNDERFLOW)
    {
        cout<<"\nQueue is Empty!";
    }
    catch(QueueL<int>::OVERFLOW)
    {
        cout<<"\nQueue is Full!";
    }
    }
    return 0;
}
