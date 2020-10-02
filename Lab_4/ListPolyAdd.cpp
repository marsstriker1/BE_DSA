#include <iostream>
#include <iomanip>
#include "List.h"
using namespace std;
class Poly
{
    const int coefNum1;
    const int coefNum2;
public:
    List<float> p1;
    List<float> p2;
    Poly(int n1,int n2):coefNum1(n1),coefNum2(n2)
    {
        p1.setMax(coefNum1+1);
        p2.setMax(coefNum2+1);
    }
    void getInput();
    void displayP(List<float>);
    List<float> add(List<float> ,List <float> );
    void calc();
};
void Poly::displayP(List<float> _list)
{
    for(int i=_list.sizeG();i>0;i--)
    {
        cout<<_list.removeFromFront()<<"x^"<<i-1<<" + ";
    }
    cout<<"\b\b\b\b\b\b      \b\b\b\b\b\b";
}
void Poly::calc()
{
    List<float> res;
    res=add(p1,p2);
    cout<<"\t";
    displayP(res);
}
List<float> Poly::add(List<float> La,List <float> Lb)
{
    int diff;
    List<float> a=La;
    List<float> b=Lb;
    List<float> res;
    cout<<"\n--------------------------------ADDING--------------------------------\n\t";
    displayP(La);
    cout<<"\n\n+\t";
    displayP(Lb);
    cout<<"\n--------------------------------------------------------\n";
    if(coefNum1>=coefNum2)
    {
        diff=coefNum1-coefNum2;
        List<float> sum(coefNum1+1);
        for(int i=0;i<diff;i++)
        {
            sum.insertAtEnd(a.removeFromFront());
        }
        for(int i=0;i<=coefNum1-diff+1;i++)
        {
            try
            {
            float added=a.removeFromFront()+b.removeFromFront();
            sum.insertAtEnd(added);
            }
            catch(List<float>::UNDERFLOW)
            {
                cout<<"";
            }
        }
        res=sum;
    }
    else
    {
        diff=coefNum2-coefNum1;
        List<float> sum(coefNum2+1);
        for(int i=0;i<diff;i++)
        {
            sum.insertAtEnd(b.removeFromFront());
        }
        for(int i=0;i<=coefNum1-diff+1;i++)
        {
            float added=a.removeFromFront()+b.removeFromFront();
            sum.insertAtEnd(added);
        }
        res=sum;
    }
    return res;
}
void Poly::getInput()
{
    cout<<"Enter first Polynomial:\n";
    for(int i=0;i<=coefNum1;i++)
    {
        float num;
        cout<<"Coefficient of x^"<<i<<" :";
        cin>>num;
        p1.insertAtFront(num);
    }
    cout<<"Enter second Polynomial:\n";
    for(int i=0;i<=coefNum2;i++)
    {
        float num;
        cout<<"Coefficient of x^"<<i<<" :";
        cin>>num;
        p2.insertAtFront(num);
    }
}
int main()
{
    int deg1,deg2;
    List<float> l;
    try
    {
        cout<<"Enter Degree of Polynomial 1:";
        cin>>deg1;
        cout<<"Enter Degree of Polynomial 2:";
        cin>>deg2;
        Poly p(deg1,deg2);
        p.getInput();
        cout<<"\nSUM:\n";
        p.calc();
    }
    catch(List<float>::OVERFLOW())
    {
        cout<<"Too many coefficients!";
    }
}

