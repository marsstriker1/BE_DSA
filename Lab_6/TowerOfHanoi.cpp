#include <iostream>
// #include <ctime>
void printInstructions(const char* source, const char* destination)
{
    std::cout<<"Move disc from "<<source<<" to "<<destination<<".\n";
}
void hanoi(int num,const char* source, const char* via, const char* destination)
{
    if(num==0)
        return;
    hanoi(num-1,source,destination,via);
    printInstructions(source,destination);
    hanoi(num-1,via,source,destination);
}
int main()
{
   int num;
   std::cout<<"Enter the number of discs:";
   std::cin>>num;
//    float a =clock();
   hanoi(num,"A","B","C");
//    std::cout<<(clock()-a)/CLOCKS_PER_SEC<<'\n';
    return 0;
}