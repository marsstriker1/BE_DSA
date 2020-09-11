#include <iostream>

using namespace std;


class ArithmeticOps
{
    public:
    class ZERO{};
    class OPERR{};
    static float operate(float term1,float term2,char op)
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
            {
                if(term2==0)
                throw(ZERO());
                return term1/term2;  
            }
            default:
                throw(OPERR());
                
        }   
    }
};

int main()
{
    
    float val1,val2,res;
    char op;
    cout<<"Enter Operation: ";
    cin>>val1;
    cin>>op;
    cin>>val2;
    try
    {
        res=ArithmeticOps::operate(val1,val2,op);
        cout<<"\nThe result is: "<<res;
    }
    catch(ArithmeticOps::ZERO)
    {
        cout<<"Can't divide by Zero!";
    }
    catch(ArithmeticOps::OPERR)
    {
        cout<<"Invalid Operator!";
    }
}