#include <iostream>

using namespace std;

template<class T>
class Swap
{
    T a;
    T b;
    public:
    Swap(T m1=0,T m2=0)
    {
        a=m1;
        b=m2;
    }
    void showProp()
    {
        cout<<"\nA = "<<this->a<<"\tB = "<<b;
    }
    void swapProp()
    {
        T temp;
        temp =a;
        a=b;
        b=temp;
    }
};

int main()
{
    Swap<int> i(5,3);
    Swap<double> d(3.3222,545.3212);
    Swap<char> c('a','b');
    cout<<"\nBefore swapping:";
    i.showProp();
    d.showProp();
    c.showProp();
    
    i.swapProp();
    d.swapProp();
    c.swapProp();
    
    cout<<"\nAfter swapping:";
    i.showProp();
    d.showProp();
    c.showProp();
}