#include<bits/stdc++.h>
using namespace std;

int toDigit(char c)
{
    if(c>47 && c<58)
        return ( c - 48);
    else
        return -1;
}
bool isOperator(char symbol)
{
    if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/' || symbol=='^')
    return true;
    return false;
}
int getRes(float a, float b, char op)
{
    switch(op)
            {
                case '+':
                    return b+a;
                case '-':
                    return b-a;
                case '*':
                    return b*a;
                case '/':
                    return b/a;
                case '^':
                    return pow(b,a);
                default:
                {
                cout<<"error!";
                exit(0);
                }
            }
}
int main()
{
    string  postfix;
    char symbol;
    int operand = 0;
    stack<int> opStack;
    opStack.push('N');
    int op1, op2;

    cout<<"\nEnter the postfix expression to evaluate [e.g. 10,20* ]  ";
    cin>>postfix;

     for(int i=0 , p = -1;i<postfix.length();i++)
     {
        symbol = postfix[i];
         if(toDigit(symbol) != -1)
         {
             if(i == postfix.length() -1)
             {
                 cout<<"\nInvalid expression!!";
                 exit(0);
             }
            p++;
         }
         else if(symbol == ',' || isOperator(symbol) && !isOperator(postfix[i-1]))
         {
            for( ;p>=0;p--)
                operand += pow(10,p)*toDigit(postfix[i-p-1]);

            opStack.push(operand);
            operand = 0;
         }
         else if (isOperator(postfix[i-1])) {}
         else
         {
            cout<<"\nInvalid symbol in expression!!";
            exit(0);
         }

         if(isOperator(symbol))
         {
        //   try{
             op2 = opStack.top();
             opStack.pop();
             op1 = opStack.top();
             opStack.pop();
             opStack.push(getRes(op2,op1,symbol));
            //  }
            //  catch(Stack<int>::UNDERFLOW)
            //  {
            //      cout<<"\nInvalid expression!!";
            //      exit(0);
            //  }
         }
    }
    int result = opStack.top();
    opStack.pop();

    if(opStack.top()=='N')
        cout<<postfix<<" = "<<result;
    else
        cout<<"\nInvalid expression";
}