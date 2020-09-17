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
  class OVERFLOW{};
  class UNDERFLOW{};
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
      if(rear==-1 || front==SIZE-1)
      {
          throw(UNDERFLOW());
          return true;
      }
      return false;
  }
  void enqueue(t item)
  {    
      if(!isFull())
      {
              rear++;
              q[rear]=item;
      }
  }
  t dequeue()
  {
      t data;
      if(!isEmpty() )
      {
          front++;
          data=q[front];
      }
      return data;
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
    if(sel==1)
    {
        cout<<"Enter data: ";
        cin>>n;
        a.enqueue(n);
    }
    else if(sel==2)
    {
        cout<<a.dequeue();
    }
    else
    {
        cout<<"Invalid choice!";
    }
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