#include <iostream>
double fact(double n)
{
    if(n==1)
    {
        return 1;
    }
    return n*fact(n-1);
}

int main()
{
    double num;
    std::cout<<"Enter Number:\t";
    std::cin>>num;
    std::cout<<std::endl<<"Factorial of "<<num<<" is "<<fact(num)<<"."<<std::endl;
    return 0;
}
// #include <gmp.h>
// #include <iostream>
// mpz_t fact(mpz_t n)
// {
//     if(n==1)
//     {
//         return 1;
//     }
//     return n*fact(n-1);
// }

// int main()
// {
//     mpz_t num;
//     mpz_init(num);
//     std::cout<<"Enter Number:\t";
//     std::cin>>num;
//     std::cout<<std::endl<<"Factorial of "<<num;//fact(num)<<"."<<std::endl;
// }

// #include <iostream>
// #include <gmpxx.h>
// using namespace std;
// mpz_class fact(unsigned int n)
// {
//     mpz_class result(n); // initialize an arbitrary-sized integer with 'n'
//     while(n-- > 1) result *= n; // compute the product with every integers < n
//     return result;
// }

// int main()
// {
//     unsigned n = 5;
//     mpz_class result = fact(n);
//     std::cout << result << std::endl;
// }
