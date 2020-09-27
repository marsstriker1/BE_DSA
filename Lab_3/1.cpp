#include<iostream>
#include<conio.h>
#include "list.h"

int main()
{
    List<int> i;
    int no,index,selection;

    while(true)
    {
        try
        {
            std::cout<<"\n\nEnter operation to perform: 1.INSERT  2.INSERT-AT-INDEX  3.REMOVE  4.REMOVE-FROM-INDEX  5.EXIT  ";
            std::cin>>selection;

            if(selection == 1)
            {
                std::cout<<"\nEnter number to insert ";
                std::cin>>no;
                i.insert(no);
            }
            else if(selection == 2)
            {
                std::cout<<"\nEnter number to insert ";
                std::cin>>no;
                std::cout<<"Enter the index ";
                std::cin>>index;
                i.insert(index,no);
            }
            else if(selection == 3)
            {
                std::cout<<"\n";
                i.remove();
            }
            else if(selection == 4)
            {
                std::cout<<"\nEnter the index ";
                std::cin>>index;
                i.remove(index);
            }
            else{ break;}
            std::cout<<"\nLIST: ";
            i.display();
        }
        catch(List<int>::EMPTY)
        {
            std::cout<<"\nQueue is Empty!";
        }
        catch(List<int>::INVALID_INDEX)
        {
            std::cout<<"\nINVALID INDEX! ";
        }
    }
}

