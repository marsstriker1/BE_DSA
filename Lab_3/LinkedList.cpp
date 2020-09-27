#include<iostream>
template<class T>
class Node
{
public:
    T item;
    Node<T>* next;
};

template<class T>
class List
{
    Node<T>* start;
public:
    class EMPTY{};
    class INVALID_INDEX{};
    List()
    {
        start = nullptr;
    }
    ~List()
    {
      if(start != nullptr)
       {
           Node<T>* p = start;
           Node<T>* q = p->next;
           if( q == nullptr)
                delete p;
           else
           for(; q != nullptr ; p = q , q = q->next)
              delete p;
       }
    }
 void insertAtBeg(T _item);
 void insertAtEnd(T _item);
 void insertAfter(Node<T>* spNode,T _item);
 void insertBefore(Node<T>* spNode,T _item);
 T deleteAfter(Node<T>* spNode);
 T deleteFromBeg();
 T deleteFromEnd();
 Node<T>* getNode(int index);
 void display();
};

template<class T>
void List<T>::insertAtBeg(T _item)
    {
        Node<T>* newNode = new Node<T>();
        newNode->item = _item;
        if (start == nullptr)
        {
            newNode->next = nullptr;
            start = newNode;
        }
        else
        {
            newNode->next = start;
            start = newNode;
        }
    }
template<class T>
void List<T>::insertAtEnd(T _item)
    {
        Node<T>* newNode = new Node<T>();
        newNode->item = _item;
        newNode->next = nullptr;
        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            Node<T>* p = start;
            Node<T>* q = p->next;
                for(; q != nullptr ; p = q , q = p->next) ;
            p->next = newNode;
        }
    }
template<class T>
void List<T>::insertAfter(Node<T>* spNode,T _item)
    {
        Node<T>* newNode = new Node<T>();
        newNode->item = _item;
        newNode->next = spNode->next;
        spNode->next = newNode;
    }
template<class T>
void List<T>::insertBefore(Node<T>* spNode,T _item)
    {
        Node<T>* newNode = new Node<T>();
        newNode->item = _item;
        if(spNode == start)
        {
            insertAtBeg(_item);
            return;
        }

        Node<T>* p = start;
        Node<T>* q = p->next;
            for(; q != spNode ; p = q , q = p->next) ;
        newNode->next = p->next;
        p->next = newNode;
    }

template<class T>
   T List<T>::deleteFromBeg()
    {
        if(start == nullptr)
            throw EMPTY();
        Node<T>* temp = start;
        start = start->next;
        delete temp;
    }
template<class T>
T List<T>::deleteFromEnd()
    {
        if(start == nullptr)
            throw EMPTY();
        T temp;
        Node<T>* p = start;
        Node<T>* q = nullptr;
            for(;p->next != nullptr; q = p, p = p->next) ;
        if(q == nullptr)
        {   
            start = nullptr;
        }
        else
        {   
            q->next = nullptr;  
        }
        temp = p->item;
        delete p;
        return  temp;
    }
template<class T>
T List<T>::deleteAfter(Node<T>* spNode)
    {
        T temp;
        Node<T>* tempNode;
        tempNode = spNode->next;
        temp = tempNode->item;
        spNode->next = tempNode->next;
        delete tempNode;
        return  temp;
    }
template<class T>
Node<T>* List<T>::getNode(int index)
{
    if(start == nullptr)
        throw EMPTY();
    Node<T>* p = start;
    for(int i=0;i<index;i++)
    {
        if(p == nullptr)
            throw INVALID_INDEX();
        p = p->next;
    }
    return p;
}
template<class T>
void List<T>::display()
{
    if(start == nullptr)
        throw EMPTY();
    Node<T>* p = start;
    for(; p != nullptr ; p = p->next)
        std::cout<<" "<<p->item;
}

int main()
{
    List<int> ilist;
    int no ,index,selection;
    Node<int>* ptr;

    while(true)
    {
        try
        {
            std::cout<<"\nEnter operation to perform: 1.INSERT  2.DELETE 3.EXIT  ";
            std::cin>>selection;
            if(selection == 1)
            {
                std::cout<<"\nWhere to insert: 1.BEGINING  2.BEFORE-INDEX  3.AFTER-INDEX  4.END ";
                std::cin>>selection;
                std::cout<<"\nEnter a number to insert: ";
                std::cin>>no;
                if(selection == 1)
                    ilist.insertAtBeg(no);
                else if(selection == 4)
                    ilist.insertAtEnd(no);
                else if(selection == 2)
                {
                    std::cout<<"Enter index ";
                    std::cin>>index;
                    ptr = ilist.getNode(index);
                    ilist.insertBefore(ptr,no);
                }
                else if(selection == 3)
                {
                    std::cout<<"Enter index ";
                    std::cin>>index;
                    ptr = ilist.getNode(index);
                    ilist.insertAfter(ptr,no);
                }
                else
                {
                    break;
                }
            }
            else if(selection == 2)
            {
                std::cout<<"\nWhere to delete from: 1.BEGINING  2.AFTER-INDEX  3.END ";
                std::cin>>selection;
                if(selection == 1)
                {
                    std::cout<<"\n";
                    ilist.deleteFromBeg();
                }
                else if(selection == 3)
                {
                    std::cout<<"\n";
                    ilist.deleteFromEnd();
                }
                else if(selection == 2)
                {
                    std::cout<<"\nEnter index ";
                    std::cin>>index;
                    ptr = ilist.getNode(index);
                    ilist.deleteAfter(ptr);
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
           std::cout<<"\nLIST: ";
           ilist.display();
        }
        catch(List<int>::EMPTY)
        {
            std::cout<<"List is Empty! ";
        }
        catch(List<int>::INVALID_INDEX)
        {
            std::cout<<" INVALID INDEX!! ";
        }
    }
return 0;
}
