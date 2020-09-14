#include <iostream>

using namespace std;
template<class t>
class Queue
{
  int front;
  int rear;
  const int SIZE;
  t * q;
  bool first;
  
  public:
  Queue(int n):SIZE(n)
  {
      q=new t[SIZE];
      front=0;
      rear=0;
      first =true;
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
      if(front==rear && front==0)
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
          if(!first)
              rear++;
              q[rear]=item;
              first=false;
        cout<<rear<<endl;
      }
  }
  t dequeue()
  {
      t data;
      if(!isEmpty())
      {
          data=q[front];
          if(front!=rear)
          front++;
      }
      return data;
  }
  
};
int main()
{
    Queue<int> a(5);
    char op;
    int sel,n;
    do
    {
    try
    {
    cout<<"Enter operation: ";
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
    cout<<"Continue?:";
    cin>>op;
    }while(toupper(op)=='Y');
    return 0;
}