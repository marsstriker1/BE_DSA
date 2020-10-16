#include <iostream>
template <class t>
struct NODE
{
    t item;
    NODE<t>* next;
    NODE<t>* prev;
};
template <class t>
class DoublyLinkedList
{
    typedef NODE<t> Node;
    Node * start;
    public:
    class UNDERFLOW{};
    class INVALID_INDEX{};
    DoublyLinkedList()
    {
        start=nullptr;
    }
    ~DoublyLinkedList()
    {
        if(start==nullptr)
            delete start;
        else
        {
            Node * p=start;
            Node * q =nullptr;
            for(;p->next!=nullptr;q=p,p=p->next)
            delete p;
        }
    }
    void display();
    Node* getNodeAtIndex(int);
    void insertAtFront(t);
    void insertAtEnd(t);
    void insertAfter(Node*,t);
    void insertBefore(Node*,t);
    t deleteFromFront();
    t deleteFromEnd();
    t deleteBefore(Node *);
    t deleteAfter(Node *);
};

template <class t>
void DoublyLinkedList<t>::display()
{
    if(start==nullptr)
        throw UNDERFLOW();
    std::cout<<"Data in List:\t";
    for(Node* n=start;n!=nullptr;n=n->next)
    {
        std::cout<<'\t'<<n->item;
    }
    std::cout<<"\n";
}

template <class t>
NODE<t> * DoublyLinkedList<t>::getNodeAtIndex(int index)
{
    if(start==nullptr)
        throw UNDERFLOW();
    if(index<0)
        throw UNDERFLOW();
    Node* node = start;
    for(int i=0;i<index;i++)
    {
        node=node->next;
        if(node==nullptr)
            throw INVALID_INDEX();
    }
    return node;
}
template <class t>
void DoublyLinkedList<t>::insertAtFront(t data)
{
    Node * newNode=new Node();
    newNode->item=data;
    newNode->prev=nullptr;
    if(start==nullptr)
    {
        newNode->next=nullptr;
        start=newNode;
    }
    else
    {
        start->prev = newNode;
        newNode->next = start;
        start = newNode;
    }
}

template <class t>
void DoublyLinkedList<t>::insertAtEnd(t data)
{
    Node * newNode=new Node();
    newNode->item=data;
    newNode->next=nullptr;

    if(start==nullptr)
    {
        newNode->prev=nullptr;
        start=newNode;
    }
    else
    {
        Node * p= start;
        for(;p->next!=nullptr;p=p->next);
        p->next = newNode;
        newNode->prev=p;
    }
}

template <class t>
void DoublyLinkedList<t>::insertAfter(Node* spNode,t data)
{
    Node* newNode = new Node();

    newNode->item=data;
    newNode->next=spNode->next;
    newNode->prev=spNode;

    spNode->next=newNode;
}

template <class t>
void DoublyLinkedList<t>::insertBefore(Node* spNode,t data)
{
    Node * newNode= new Node();

    newNode->item = data;
    newNode->prev = spNode->prev;
    newNode->next = spNode;

    if(spNode!=start)
        (spNode->prev)->next = newNode;
    else
                start = newNode;
    spNode->prev= newNode;
}

template <class t>
t DoublyLinkedList<t>::deleteFromFront()
{
    if(start==nullptr)
        throw UNDERFLOW();

    Node* tempNode = start;
    t temp = tempNode->item;

    start=start->next;

    if(start!=nullptr)
        start->prev=nullptr;
    delete tempNode;
    return temp;
}

template <class t>
t DoublyLinkedList<t>::deleteFromEnd()
{
    bool loopEntered=false;     //is set to true if list has mode than 1 nodes
    if(start==nullptr)
        throw UNDERFLOW();
    Node * tempNode = start;
    for(;tempNode->next!=nullptr;tempNode=tempNode->next)
    {
        loopEntered=true;
    }
    t temp = tempNode->item;
    if(!loopEntered)
    {
        start=nullptr;
    }
    else
    {
        (tempNode->prev)->next=nullptr; //disconnectiong last node
    }
    delete tempNode;
    return temp;
}

template <class t>
t DoublyLinkedList<t>::deleteBefore(NODE<t>* spNode)
{
    if(spNode == start)
        throw INVALID_INDEX();
    t temp;
    Node * tempNode;
    tempNode = spNode->prev;
    temp = tempNode->item;
    if(spNode->prev==start)
    {
        start = spNode;
        start->prev=nullptr;
    }
    else
    {
        (tempNode->prev)->next=spNode;
         spNode->prev=tempNode->prev;
    }
    delete tempNode;
    return temp;
}

template <class t>
t DoublyLinkedList<t>::deleteAfter(Node * spNode)
{
    if(spNode->next == nullptr)
        throw INVALID_INDEX();
    t temp;
    Node * tempNode;

    tempNode = spNode->next;
    temp = tempNode->item;
    if(tempNode->next!=nullptr)
        (tempNode->next)->prev = spNode;

    spNode->next=tempNode->next;
    delete tempNode;
    return temp;
}
class INVALID_SELECTION{};
int main()
{
    int sel;
    DoublyLinkedList<int> dl;
    int num,index;
    while(1)
    {
        try
        {
            std::cout<<"\nEnter Operation:\t1)Insert\t2)Delete\t3)Exit\t";
            std::cin>>sel;
            if(sel==1)
            {
                std::cout<<"Insert at:\t\t1)Beginning\t2)End\t3)Before index\t4)After index\t";
                std::cin>>sel;
                if(sel<=0 || sel>4)
                    throw INVALID_SELECTION();
                std::cout<<"Enter the number:\t";// to be inserted:\t";
                std::cin>>num;
                if(sel==1)
                    dl.insertAtFront(num);
                else if(sel==2)
                    dl.insertAtEnd(num);
                else if(sel==3 || sel==4)
                {
                    std::cout<<"Enter index:\t\t";
                    std::cin>>index;
                    NODE<int>* node = dl.getNodeAtIndex(index);
                    if(sel==3)
                        dl.insertBefore(node,num);
                    else
                        dl.insertAfter(node,num);
                }
            }
            else if(sel==2)
            {
                int data;
                std::cout<<"Delete from:\t\t1)Beginning\t2)End\t3)Before index\t4)After index\t";
                std::cin>>sel;
                if(sel==1)
                    data = dl.deleteFromFront();
                else if(sel==2)
                    data = dl.deleteFromEnd();
                else if(sel==3 || sel==4)
                {
                    std::cout<<"Enter index:\t\t";
                    std::cin>>index;
                    NODE<int>* node = dl.getNodeAtIndex(index);
                    if(sel==3)
                        data = dl.deleteBefore(node);
                    else
                        data = dl.deleteAfter(node);
                }
                else
                {
                    throw INVALID_SELECTION();
                }
                std::cout<<data<<" deleted.\n";
            }
            else
            {
                exit(0);
            }
            dl.display();
        }
        catch(DoublyLinkedList<int>::UNDERFLOW)
        {
            std::cerr<<"List is empty!\n";
        }
        catch(DoublyLinkedList<int>::INVALID_INDEX)
        {
            std::cerr<<"Inavlid index selected!\n";
        }
        catch(INVALID_SELECTION)
        {
            std::cerr<<"Invalid Option Selected!\n";
        }
    }
    return 0;
}
