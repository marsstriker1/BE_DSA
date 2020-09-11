#include <iostream>

using namespace std;

template <class t> 
class Stack
{
  static const int max =5;
  int top=-1;
  t stack[max];
  
  public:
  bool isFull()
  {
    if(top==max)
        return true;
    return false;
  }
  bool isEmpty()
  {
    if(top==-1)
        return true;
    return false;
  }
  t pop()
  {
      t item;
      if(!isEmpty())
      {
          item = stack[top];
          top--;
      }
      else
      cout<<"Stack is empty!\nYou must add an item to proceed.";
      return item;
  }
  void push(t data)
  {
      if(!isFull())
      {
          top++;
          stack[top]=data;
      }
      else
      cout<<"Stack is Full!\nYou must pop an item to proceed.";  
  }
  void showStack()
  {
      cout<<"\nStack:";
      for(int i=0;i<=top;i++)
      cout<<endl<<i<<"="<<stack[i];
      cout<<"\n................................\n";
  }
};
int main()
{
    //cout<<"Enter type data to be entered:\n1)Number\n2)Character";
    Stack <int> s;
    int item;
    char choice,op;
    
    do
    {
    cout<<"Which operation do you want to perform?\n1)Push\n2)Pop";
    cin>>choice;
    switch(choice)
    {
        case '1':
        {
            cout<<"Enter number to be pushed:";
            cin>>item;
            s.push(item);
            break;
        }
        case '2':
        {
            
            cout<<s.pop()<<" Popped";
            break;
        }
        default:
        {
            cout<<"Invalid Operation!";
            op='y';
        }
    }
    cout<<"Do you want to continue?(Y or N)";
    cin>>op;
    s.showStack();
    } while (toupper(op)=='Y');
    return 0;
}