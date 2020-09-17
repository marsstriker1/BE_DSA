#include <iostream>
using namespace std;
template <class t>
class Deque
{
    const int SIZE;
    int front;
    int rear;
    t * d;

    public:
    class OVERFLOW{};
    class UNDERFLOW{};
  Deque(int n):SIZE(n)
  {
      d=new t[SIZE];
      front=-1;
      rear=-1;
  }
  ~Deque()
  {
      delete []d;
  }
  void addBegin(t item)
  {
      if((front==0 && rear==SIZE-1) || (front==rear+1))
      {
          throw(OVERFLOW());
      }
      else if(front == rear && rear==-1)
      {
          front =0;
          rear=0;
          d[front]=item;
      }
      else if(front ==0)
      {
          front =SIZE-1; 
          d[front]=item;
      }
      else
      {
          front--;
          d[front]=item;
      }
  }
  void addEnd(t item)
  {
      if((front==0 && rear==SIZE-1) || (front==rear+1))
      {
          throw(OVERFLOW());
      }
      else if(front==rear && rear==-1)
      {
          front=0;
          rear=0;
          d[rear]=item;
      }
      else if(rear==SIZE-1)
      {
          rear=0;
          d[rear]=item;
      }
      else
      {
          rear++;
          d[rear]=item;
      }
  }
 t delBegin()
  {
      t data;
      if(front==rear && rear==-1)
      {
          throw(UNDERFLOW());
      }
      else if(front == rear)
      {
          data= d[front];
          front=-1;
          rear=-1;
      }
      else if(front==SIZE-1)
      {
          data= d[front];
          front=0;
      }
      else
      {
          data=d[front];
          front++;
      }
      return data;
  }
  t delEnd()
  {
      t data;
      if(front==rear && rear==-1)
      {
          throw(UNDERFLOW());
      }
      else if(front == rear)
      {
          data= d[front];
          front=-1;
          rear=-1;
      }
      else if(rear==0)
      {
          data= d[rear];
          rear=SIZE-1;
      }
      else
      {
          data=d[rear];
          rear--;
      }
      return data;      
  }
};
int main()
{
    int sizeQ;
    cout<<"Enter Dueqe Size: ";
    cin>>sizeQ;
    Deque<int> a(sizeQ);
    char op;
    int sel,n;
    do
    {
    try
    {
    cout<<"Enter operation: \n1)Add at Begining\n2)Add at end\n3)Delete from Begining\n4)Delete from End\t";
    cin>>sel;
    switch (sel)
    {
        case (1):
        {
            cout<<"Enter data: ";
            cin>>n;
            a.addBegin(n);
            break;
        }
        case (2):
        {
            cout<<"Enter data: ";
            cin>>n;
            a.addEnd(n);
            break;
        }
        case(3):
        {
            a.delBegin();
            break;
        }
        case(4):
        {
            a.delEnd();
            break;
        }
        default:
        {
            cout<<"Invalid choice!";
        }
    }
    // else if(sel==3)
    // {
    //     a.delBegin();
    // }
    // else if(sel==4)
    // else 
    // {
        
    // }
    }
    catch(Deque<int>::OVERFLOW)
    {
        cout<<"Deque is full!";
        op=='Y';
    }
    catch(Deque<int>::UNDERFLOW)
    {
        cout<<"Deque is empty!";
        op=='Y';
    }
    cout<<"\nContinue?:";
    cin>>op;
    // a.show();
    }while(toupper(op)=='Y' || op=='1');
    return 0;
}