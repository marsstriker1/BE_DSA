#include <iostream>

using namespace std;

template <class T>
void swAp(T *a, T *b)
{
    T temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int a=1,b=2;
    double c=5.1,d=6.34;
    char e='e',f ='f';
    cout<<"The initial data before swapping are:\nInteger\na = "<<a<<" b="<<b;
    cout<<"\nDouble\nc = "<<c<<" d="<<d;
    cout<<"\nChar\ne = "<<e<<" f = "<<f<<endl;
    swAp(&a,&b);
    swAp(&c,&d);
    swAp(&e,&f);
    cout<<"After swapping:\nIntegers\na = "<<a<<" b = "<<b;
    cout<<"\nDouble\nc = "<<c<<" d = "<<d;
    cout<<"\nChar\ne = "<<e<<"f = "<<f;
}