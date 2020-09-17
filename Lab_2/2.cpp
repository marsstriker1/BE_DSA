#include <iostream>
using namespace std;
template<class t>
class CQueue
{
  int front;
  int rear;
  const int SIZE;
  t * q;
  
  public:
  CQueue(int n):SIZE(n)
  {
      q=new t[SIZE];
      front=-1;
      rear=-1;
  }
  ~CQueue()
  {
      delete []q;
  }
  class OVERFLOW{};
  class UNDERFLOW{};

  void enqueue(t item)
  {    
      if(front==rear && rear==-1)
      {
          front=0;
          rear=0;
          q[rear]=item;
      }
      else if((rear+1)%SIZE==front)
      {
          throw(OVERFLOW());
      }
      else
      {
          rear=(rear+1)%SIZE;
          q[rear]=item;
      }
  }
   t dequeue()
  {
      t data;
      if(front==rear && front==-1)
      {
          throw (UNDERFLOW());
      }
      else if( front == rear)
      {
          data=q[front];
          front =-1;
          rear = -1;
      }
      else
      {
          data=q[front];
          front=(front+1)%SIZE;
      }
      
      return data;
  }
  void show()
  {
      for(int i=0;i<SIZE;i++)
      {
          cout<<"\n"<<i<<" = "<<q[i]<<endl;
      }
  }
};

int main()
{
    int sizeQ;
    cout<<"Enter Queue Size: ";
    cin>>sizeQ;
    CQueue<int> a(sizeQ);
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
    catch(CQueue<int>::OVERFLOW)
    {
        cout<<"Queue is full!";
        op=='Y';
    }
    catch(CQueue<int>::UNDERFLOW)
    {
        cout<<"Queue is empty!";
        op=='Y';
    }
    cout<<"\nContinue?:";
    cin>>op;
    a.show();
    }while(toupper(op)=='Y' || op=='1');
    return 0;
}