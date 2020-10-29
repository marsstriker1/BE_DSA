#include <iostream>
long double fact(long double n)
{
    std::cout<<n<<"*";
    if(n==1)
    {
        std::cout<<"\b \b = ";
        return 1;
    }
    return n*fact(n-1);
}
int main()
{
    long double num;
    std::cout<<"Enter Number:\t";
    std::cin>>num;
    if(num<0)
    {
        std::cout<<"\nCan't find factorial of negative number";
        exit(0);
    }
    std::cout<<"\nFactorial of "<<num<<" is "<<fact(num)<<"."<<std::endl;
    return 0;
}
