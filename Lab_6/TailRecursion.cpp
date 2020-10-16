#include <iostream>
template <class t = int >
class Factorial
{
    static t findFact(int n,int a)
    {
        if(n==1)
            return a;
        return findFact(n-1,a*n);
    }
public:
    class INVALID_NUMBER{};
    static t findFactFor(t num)
    {
        if(num<0)
            throw INVALID_NUMBER();
        return findFact(num,1);
    }

};

template <class t = long>
class Fibonacci
{
    static t findFibbTerm(int n,int a,int b)
    {
        if(n==0)
            return b;
        return findFibbTerm(n-1,a+b,a);
    }
public:
    class INVALID_NUMBER{};
    static t findFibb(t num)
    {
        if(num<0)
            throw INVALID_NUMBER();
        findFibbTerm(num,1,0);
    }
    static void displayFibb(t num)
    {
        if(num<0)
            throw INVALID_NUMBER();

        std::cout<<"\nThe Fibonacci series is:\n";

        for(t i=1;i<=num;i++)
            std::cout<<findFibbTerm(i,1,0)<<" ";
        std::cout<<'\n';
    }
};

int main()
{
    int num;
    std::cout<<"\nChoose Operation:\n1)Factorial\n2)Fibonacci\t";
    std::cin>>num;
    try
    {
        if(num == 1)
        {
            std::cout<<"\nEnter the number to evaluate factorial:\t";
            std::cin>>num;
            int ans = Factorial<int>::findFactFor(num);
            std::cout<<"\nThe factorial of "<<num<<" is "<<ans;
        }
        else if(num == 2)
        {
            std::cout<<"\nChoose Operation:\n1)Find nth term\n2)Show series upto n\t";
            std::cin>>num;
            if(num == 1)
            {
                std::cout<<"\nEnter 'n' to evaluate Fibonacci:\t";
                std::cin>>num;
                int ans = Fibonacci<>::findFibb(num);
                std::cout<<"\nThe "<<num<<"th Fibonacci term is: "<<ans;
            }
            else if(num == 2)
            {
                std::cout<<"\nEnter 'n' to evaluate Fibonacci:\t";
                std::cin>>num;
                Fibonacci<>::displayFibb(num);
            }
        }
    }
    catch(Factorial<>::INVALID_NUMBER)
    {
        std::cout<<"\nCannot find factorial of negative number.";
    }
    catch(Fibonacci<>::INVALID_NUMBER)
    {
        std::cout<<"\nCannot find Fibonacci for negative 'n'.";
    }
    return 0;
}
