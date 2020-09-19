/*WAP to Perform operations in Deque( Double ended queue) for:
a. Add at beginning
b. Add at end
c. Delete from beginning
d. Delete from end*/
#include <iostream>
using namespace std;
template <class t>
class Deque
{
    const int SIZE;
    int front;
    int rear;
    int count;
    t * d;

    public:
    class OVERFLOW{};
    class UNDERFLOW{};
  Deque(int n):SIZE(n)
  {
      d=new t[SIZE];
      front=-1;
      rear=-1;
      count=0;
  }
  ~Deque()
  {
      delete []d;
  }
  void addBegin(t item)
  {
      if((front==0 && rear==SIZE-1) || (front==rear+1)) /*Deque full condition*/
      {
          throw(OVERFLOW());
      }
      else if(front == rear && rear==-1)                /*Initial condition*/
      {
          front =0;
          rear=0;
          d[front]=item;
          count++;
      }
      else if(front ==0)                                /*front-- becomes 0 which is not required outcome*/
      {
          front =SIZE-1; 
          d[front]=item;
          count++;
      }
      else
      {
          front--;
          d[front]=item;
          count++;
      }
  }
  void addEnd(t item)                               /*Deque full condition*/
  {
      if((front==0 && rear==SIZE-1) || (front==rear+1))
      {
          throw(OVERFLOW());
      }
      else if(front==rear && rear==-1)              /*Initial Condition*/
      {
          front=0;
          rear=0;
          d[rear]=item;
          count++;
      }
      else if(rear==SIZE-1)                         
      {
          rear=0;
          d[rear]=item;
          count++;
      }
      else
      {
          rear++;
          d[rear]=item;
          count++;
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
          count--;
      }
      else if(front==SIZE-1)
      {
          data= d[front];
          front=0;
          count--;
      }
      else
      {
          data=d[front];
          front++;
          count--;
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
          count--;
      }
      else if(rear==0)
      {
          data= d[rear];
          rear=SIZE-1;
          count--;
      }
      else
      {
          data=d[rear];
          rear--;
          count--;
      }
      return data;      
  }
  void display()
  {
      if(front==rear && rear==-1)
      {
          throw(UNDERFLOW());
      }
      else
      {
          int i=front;
          int num=0;
          bool loop=true;
          cout<<"Deque: ";
          while(loop && num<=count)
          {
              if(count==1)
              {
                  cout<<d[i]<<"\t";
                  loop=false;
              }
              else
              {
            cout<<d[i]<<"\t";
            if(i==rear && i==0)
            {
                loop=false;
            }
            else if(i==SIZE-1 && i==rear)
                {
                    cout<<d[i]<<"\t";
                    loop=false;
                }
            else    
            {
                i=(i+1)%SIZE;
                if(i==rear)
                {
                    cout<<d[i]<<"\t";
                    loop=false;
                }
            }
              }
            num++;
          }
      }
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
            cout<<a.delBegin()<< " deleted\n";
            break;
        }
        case(4):
        {
            cout<<a.delEnd()<<" deleted\n";
            break;
        }
        default:
        {
            cout<<"Invalid choice!";
        }
    }
    a.display();
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