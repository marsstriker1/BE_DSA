#include <iostream>
#include "List.h"
using namespace std;
template <class T>
class Stack
{
    const int maxM;
    List<T> l;
    public:
    Stack(int s):maxM (s)
    {
       l.setMax(maxM);
    }
    void push(T data)
    {
        l.insertAtFront(data);
    }
    T pop()
    {
        T temp=l.removeFromFront();
        return temp;
    }
    void peek()
    {
        cout<<l.peekFront();
    }
   /* void display()
    {
        l.display();
    }*/
    int stackSize()
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
    Stack<int> s(num);
    while(1)
    {
    try
    {
        cout<<"\nEnter Operation:\t1)Push\t2)Pop\t3)Exit:";
        cin>>op;
        if(op==1)
        {
            if(s.stackSize()<sizeSt)
            {
                cout<<"\nEnter number to be pushed:";
                cin>>num;
                s.push(num);
                //cout<<"\nData is stack:";
                //s.display();
                cout<<"\nTop of Stack:\t";
                s.peek();
            }
            else
            {
                throw(List<int>::OVERFLOW());
            }
        }
        else if(op==2)
        {
            s.pop();
            //cout<<"\nData is stack:";
            //s.display();
            cout<<"\nTop of Stack:\t";
            s.peek();
        }
        else
        {
           exit(0);
        }
    }

    catch(List<int>::UNDERFLOW)
    {
        cout<<"\nEmpty Stack!";
    }
    catch(List<int>::OVERFLOW)
    {
        cout<<"\nStack FULL!";
    }
    }
    return 0;
}
