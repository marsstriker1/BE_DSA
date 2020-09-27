#include<iostream>
#include<conio.h>
#include"list.h"

template<class T>
class Queue
{
    List<T> items;
public:
    void enqueue(T _item)
    {
        items.insert(_item);
    }

    T dequeue()
    {
        return items.remove(0);
    }

    void display()
    {
        items.display();
    }
};

int main()
{
    Queue<int> iqueue;
    int no,selection;

    while(true)
    {
        try
        {
            std::cout<<"\nEnter operation to perform: 1.ENQUEUE  2.DEQUEUE 3.EXIT  ";
            std::cin>>selection;
            if(selection == 1)
            {
                std::cout<<"\nEnter a number to enqueue: ";
                std::cin>>no;
                iqueue.enqueue(no);
            }
            else if(selection == 2)
            {
                std::cout<<'\n'<<iqueue.dequeue()<<" dequeued. \n";
            }
            else
            {
                break;
            }
            std::cout<<"\nQUEUE: ";
            iqueue.display();
        }
        catch(List<int>::EMPTY)
        {
            std::cout<<"\nQueue is Empty!";
        }
    }
}
