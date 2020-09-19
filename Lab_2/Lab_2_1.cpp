/*WAP to Perform enqueue and dequeue operations in Linear Queue*/
#include <iostream>
using namespace std;
template<class t>
class Queue
{
  int front;
  int rear;
  const int SIZE;
  t * q;
  
  public:
  Queue(int n):SIZE(n)
  {
      q=new t[SIZE];
      front=-1;
      rear=-1;
  }
  ~Queue()
  {
      delete []q;
  }
  class OVERFLOW{};                         /*Exception for queue is full*/
  class UNDERFLOW{};                        /*Exception for queue is empty*/
  bool isFull()
  {
      if(rear==SIZE-1)
      {
          throw(OVERFLOW());
          return true;
      }
      return false;
  }
  bool isEmpty()
  {
      if(rear==-1 || front==SIZE-1)         /*front does not go back after reaching the end even if space is available*/
      {
          throw(UNDERFLOW());
          return true;
      }
      return false;
  }
  void enqueue(t item)                      
  {    
      if(rear==-1)
      front=0;
              rear++;                       /*points rear towards next available space*/
              q[rear]=item;                 /*assigns passed data to that location*/
  }
  t dequeue()
  {
      t data;                   
          data=q[front];                    /*returns data pointed by front(Not necessary to do while performing dequeue operation)*/
          front++;                          /*points front towards next element of queue*/ 
      return data;
  }
  void show()
  {
      cout<<"Queue:\t";
      if(front==SIZE-1)
      cout<<q[front]<<"\t";
      else if(!isEmpty())
      for(int i = front;i<=rear;i++)
      cout<<q[i]<<"\t";
  }
};
int main()
{
    int sizeQ;
    cout<<"Enter Queue Size: ";
    cin>>sizeQ;
    Queue<int> a(sizeQ);
    char op;
    int sel,n;
    do
    {
    try
    {
    cout<<"Enter operation:\n1)Enqueue\n2)Dequeue:\t";
    cin>>sel;
    if(sel==1 && !a.isFull())
    {
        cout<<"Enter data: ";
        cin>>n;
        a.enqueue(n);
        cout<<n<<" enqueued\n";
    }
    else if(sel==2 && !a.isEmpty())
    {
        cout<<a.dequeue()<<" dequeued\n";
    }
    else
    {
        cout<<"Invalid choice!";
    }
    a.show();
    }
    catch(Queue<int>::OVERFLOW)
    {
        cout<<"Queue is full!";
        op=='Y';
    }
    catch(Queue<int>::UNDERFLOW)
    {
        cout<<"Queue is empty!";
        op=='Y';
    }
    cout<<"\nContinue?:";
    cin>>op;
    }while(toupper(op)=='Y' || op=='1');
    return 0;
}