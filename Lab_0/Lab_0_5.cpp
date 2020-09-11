#include <iostream>

using std::cin;
using std::cout;
template <class T>
class ArithmeticOps
{
    public:
    static T operate(T term1,T term2,char op)
    {
        switch(op)
        {
            case '+':
                return term1+term2; 
            case '-':
                return term1-term2; 
            case '*':
                return term1*term2;  
            case '/':
                return term1/term2;  
        }
    }
};
int main()
{
    float val1,val2,res;
    char op;
    cout<<"\nEnter Operation:";
    cin>>val1;
    cin>>op;
    cin>>val2;
    if(op=='/' && val2==0)
        cout<<"\nCannot divide by zero!";
    else if(op=='+' || op=='-' || op=='*' || op=='/')
    {
        ArithmeticOps<float> Ar;
        res=Ar.operate(val1,val2,op);
        cout<<"\nThe result is: "<<res;
    }
        
    else
        cout<<"\nINVALID OPERATOR!";
    return 0;
}