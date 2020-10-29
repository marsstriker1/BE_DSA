#include <iostream>
long double fibb(long double n)
{
    if(n==1 || n==0)
        return n;
    else
        return fibb(n-1)+fibb(n-2);
}
void displayFibbSeries(int n)
{
    std::cout<<"\nThe Fibonacci series upto "<<n<<"th term is:\n";
    for(int i =1;i<=n;i++)
        std::cout<<"  "<<fibb(static_cast<long double>(i));
    std::cout<<'\n';
}
int main()
{
    int num;
    while(1)
    {
    std::cout<<"\nEnter Operation:\n1)Get nth Fibonacci term\n2)Get Fibonacci series upto nth term:";
    std::cin>>num;
    if(num<0)
        std::cout<<"\nInvalid Number!";
    else if(num==1)
    {
        std::cout<<"\nEnter n:";
        std::cin>>num;
        std::cout<<num<<"th Fibonacci term is: "<<fibb(static_cast<long double>(num));
    }
    else if(num==2)
    {
        std::cout<<"\nEnter n:";
        std::cin>>num;
        displayFibbSeries(num);
    }
    else
        exit(0);
    }
}
