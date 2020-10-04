#include <iostream>
#include "List.h"
using namespace std;
template <class T>
class Queue
{
    const int maxM;
    List<T> l;
    public:
    Queue(int s):maxM (s)
    {
       l.setMax(maxM);
    }
    void enqueue(T data)
    {
        l.insertAtFront(data);
    }
    T deque()
    {
        T temp=l.removeFromEnd();
        return temp;
    }
    void display()
    {
        l.display();
    }
    int QueueSize()
    {
        return l.sizeG();
    }
};
int main()
{
    int op,sizeSt,num;
    cout<<"Size?:";
    cin>>num;
    sizeSt=num;
    Queue<int> s(num);
    while(1)
    {
    try
    {
        cout<<"\nEnter Operation:\t1)enqueue\t2)dequeue\t3)Exit:";
        cin>>op;
        if(op==1)
        {
            if(s.QueueSize()<sizeSt)
            {
                cout<<"\nEnter number to be enqueued:";
                cin>>num;
                s.enqueue(num);
                //cout<<"\nData is Queue:";
                //s.display();
                cout<<"\nTop of Queue:\t";
                s.display();
            }
            else
            {
                throw(List<int>::OVERFLOW());
            }
        }
        else if(op==2)
        {
            s.deque();
            //cout<<"\nData is Queue:";
            //s.display();
            cout<<"\nTop of Queue:\t";
            s.display();
        }
        else
        {
           exit(0);
        }
    }

    catch(List<int>::UNDERFLOW)
    {
        cout<<"\nEmpty Queue!";
    }
    catch(List<int>::OVERFLOW)
    {
        cout<<"\nQueue FULL!";
    }
    }
    return 0;
}
