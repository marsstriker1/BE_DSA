/*WAP to Perform enqueue and dequeue operations in Circular Queue*/
#include <iostream>
using namespace std;
template<class t>
class CQueue
{
  int front;
  int rear;
  int count;
  const int SIZE;
  t * q;
  
  public:
  CQueue(int n):SIZE(n)
  {
      q=new t[SIZE];
      front=-1;
      rear=-1;
      count=0;
  }
  ~CQueue()
  {
      delete []q;
  }
  class OVERFLOW{};
  class UNDERFLOW{};

bool qCon(int op)
{

    if(((rear+1)%SIZE==front) && op==1)            /*Queue is full*/
    {
        throw(OVERFLOW());
        return false;
    }
    else if((front==rear && front==-1) && op==2)  /*Queue empty condition*/
      {
          throw (UNDERFLOW());
          return false;
      }
      return true;
}
  void enqueue(t item)
  {    
      if(front==rear && rear==-1)       /*Queue empty condition*/
      {
          front=0;
          rear=0;
          q[rear]=item;
          count++;
      }
      else if((rear+1)%SIZE==front)     /*Queue is full*/
      {
          //throw(OVERFLOW());          /*handled by qCon()*/
      }
      else                              /*One or more space available in queue*/
      {
          rear=(rear+1)%SIZE;
          q[rear]=item;
          count++;
      }
  }
   t dequeue()
  {
      t data;
      if(front==rear && front==-1)  /*Queue empty condition*/
      {
          //throw (UNDERFLOW());    /*handled by qCon()*/
      }
      else if( front == rear)       /*All items have been dequeued so front and rear are changed to initial conditions*/
      {
          data=q[front];
          front =-1;
          rear = -1;
      }
      else                          /*Queue has more than 1 item*/
      {
          data=q[front];
          front=(front+1)%SIZE;
          count--;
      }
      
      return data;
  }
  void display()
  {
      if(qCon(2))
      {
          int i=front;
          int num=0;
          bool loop=true;
          cout<<"Queue: ";
          while(loop && num<=count)
          {
              if(count==1)
              {
                  cout<<q[i]<<"\t";
                  loop=false;
              }
              else
              {
            cout<<q[i]<<"\t";
            if(i==rear && i==0)
            {
                loop=false;
            }
            else if(i==SIZE-1 && i==rear)
                {
                    cout<<q[i]<<"\t";
                    loop=false;
                }
            else    
            {
                i=(i+1)%SIZE;
                if(i==rear)
                {
                    cout<<q[i]<<"\t";
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
        if(a.qCon(sel))
        {
        cout<<"Enter data: ";
        cin>>n;
        a.enqueue(n);
        cout<<n<<" enqueued.\n";
        }
    }
    else if(sel==2)
    {
        if(a.qCon(sel))
        {
            cout<<a.dequeue()<<" dequed.\n";
        }
        
    }
    else
    {
        cout<<"Invalid choice!";
    }
    a.display();
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
    }while(toupper(op)=='Y' || op=='1');
    return 0;
}