#include <iostream>
using namespace std;
template <class t>
struct NODE
{
    t coef;
    int deg;
    NODE<t>* next;
};
template <class t>
class Poly
{
    typedef NODE<t> Node;
    Node* start;
    public:
    Poly()
    {
        start=nullptr;
    }
    ~Poly()
    {
        if(start!=nullptr)
        {
            Node* p=start;
            for(;p!=nullptr;p=p->next)
            delete p;
        }
    }
    void getInput();
    void insertInPoly(t,int);
    void display();
    Poly operator+(Poly);

};
template <class t>
void Poly<t>::getInput()
{
    t coef;
    int deg;
    char op;
    do
    {
        cout<<"\nEnter coefficient: ";
        cin>>coef;
        cout<<"Enter degree: ";
        cin>>deg;
        insertInPoly(coef,deg);
        cout<<"Continue?(Y/N):";
        cin>>op;
    }while (toupper(op)=='Y');
}
template <class t>
Poly<t> Poly<t>::operator+(Poly<t> addend)
{
    Poly<t> res;
    Node* p= start;
    Node* q= addend.start;
    while(p!=nullptr && q!=nullptr)
    {
        if(p->deg==q->deg)
        {
            res.insertInPoly(p->coef + q->coef , p->deg);
            p = p->next;
            q = q->next;
        }
        else if(p->deg > q->deg)
        {
            res.insertInPoly(p->coef,p->deg);
            p = p->next;
        }
        else
        {
            res.insertInPoly(q->coef,q->deg);
            q = q->next;
        }
    }
    if(p!=nullptr)
    {
        for(;p!=nullptr;p=p->next)
        res.insertInPoly(p->coef,p->deg);
    }
    else if(q!=nullptr)
    {
        for(;q!=nullptr;q=q->next)
        res.insertInPoly(q->coef,q->deg);
    }
    return res;
}
template <class t>
void Poly<t>::insertInPoly(t coef,int deg)
{
    Node* newNode = new Node();
    newNode->coef=coef;
    newNode->deg=deg;
    newNode->next=nullptr;
    if(start==nullptr)
    {
        start=newNode;
        return;
    }
    Node* p;
    Node* q;
    for(p=start,q=nullptr;p!=nullptr && deg<=p->deg;q=p,p=p->next);
    //traverses list to the node just before node having degree less than given degree
    if(p!=nullptr && q==nullptr)
    {
        newNode->next=p;
        start=newNode;
    }
    else if(p!=nullptr && q!=nullptr)
    {
        if(q->deg==deg)
        q->coef=coef;
        else
        {
            newNode->next=q->next;
            q->next=newNode;
        }
    }
    else if(p==nullptr)
    {
        q->next=newNode;
        return;
    }
}
template <class t>
void Poly<t>::display()
{
    if(start==nullptr)
    {
        cout<<"";
        return;
    }
    Node* p=start;
    bool backsp=true;
    for(;p!=nullptr;p=p->next)
    {
        if(p->deg==0)
        {
            cout<<p->coef;
            backsp=false;
        }
        else
            cout<<p->coef<<"x^"<<p->deg<<" + ";
    }
    if(backsp)
    cout<<"\b\b\b   \b\b\b";
}
int main()
{
    Poly<int> P1,P2,res;
    cout<<"\nEnter Polynomial 1:";
    P1.getInput();
    cout<<"\nEnter Polynomial 2:";
    P2.getInput();
    cout<<"\n-------------------------Adding-------------------------\n\t";
    P1.display();
    cout<<"\n\n+\t";
    P2.display();
    cout<<"\n---------------------------------------------------------\n\t";
    res=P1+P2;
    res.display();
    return 0;
}
