#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class Function
{
    const int deg;
    double * fun;
    double * der;
    
    public:
    Function(int n=0):deg(n)   
    { 
        fun =new double[deg+1];
        der = new double[deg];
    }
    
    void getInput()
    {
        for(int i=deg;i>=0;i--)
        {
            cout<<"Enter coefficient of x^"<<i;
            cin>>fun[i];
            //cout<<"\n"<<fun[i]<<endl;
        }
    }
    void showVal(bool withDer)
    {
        for(int i=deg;i>=0;i--)
        {                
            cout<<showpos<<fun[i]<<"x^"<<noshowpos<<i<<" ";
        }
        cout<<endl;   
        if(withDer)
        {
        for(int i=deg-1;i>=0;i--)
        {                
            cout<<showpos<<der[i]<<"x^"<<noshowpos<<i<<" ";
        }
        cout<<endl;   
        }
    }
    
    double getFunVal(double pos)
    {
        double res=0;
        for(int i=0;i<deg+1;i++)
        {
            res+=((fun[i])*pow(pos,i));
        }
        return res;
    }
    double getDerVal(double pos)
    {
        double res=0;
        for(int i=1;i<deg+1;i++)
        {
            der[i-1]=fun[i]*i;
            res+=((der[i-1])*pow(pos,i-1));
        }
        return res;
    }
    ~Function()
    {
        delete []fun;
        delete []der;
    }
};
const int maxIter=50;
double absf(double x){return (x>0?x:-x);}
double calcRoot(Function * f,double ini, double tol)
{
    double fn1;
    double fn=ini;
    int iter=0;
    do{
    iter++;
    if(iter==maxIter)
    {
        cout<<"\n\t\tCouldn't find root!";
        exit(0);
    }
    cout<<"\nIteration: "<<iter<<"\t";
     if(f->getDerVal(fn)==0){fn1+=0.01*fn1;}
     fn1=fn-(f->getFunVal(fn)/f->getDerVal(fn));
     
     cout<<"X"<<iter-1<<"= "<<setw(10)<<left<<fn<<"\tX"<<iter<<"= "<<fn1;
     fn=fn1;
    }while(absf(f->getFunVal(fn1))>tol); 
    
    return fn1;
}

int main()
{
    int deg;
    double pos,ini,tol;
    cout<<"Enter Degree: ";
    cin >>deg;
    Function F(deg);
    F.getInput();
    
    cout<<"Initial Approx.";
    cin>>ini;
    cout<<"Enter Tolerance:";
    cin>>tol;
    
    cout<<"\nThe given function is: ";
    F.showVal(false);
    double ans = calcRoot(&F,ini,tol);
    
    cout<<"\n\nThe required root is"<<ans<<endl;
    //F.showVal(true);
    return 0;
}