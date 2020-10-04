#include <iostream>
#include <iomanip>
using namespace std;
template <class t>
struct NODE
{
    t item;
    NODE<t>* next;
};
template <class t>
class List
{
    typedef NODE<t> Node;
    int sizeL;
    int maxSize;
    Node* start;
public:
    //int maxSize;
    class UNDERFLOW{};
    class OVERFLOW{};
    List(int s=5):maxSize(s)
    {
        sizeL=0;
        start=nullptr;
    }
    ~List()
    {
        if(start!=nullptr)
        {
            Node* p =start;
            Node* q = p->next;
            if(q==nullptr)
                delete p;
            else
            for(;q!=nullptr;p=q,q=q->next)
                delete p;
        }
    }
    int sizeG()
    {
        return sizeL;
    }
    void setMax(int s)
    {
       maxSize=s;
    }
    t peekFront()
    {
        if(start==nullptr)
        {
            throw UNDERFLOW();
        }
        return start->item;
    }
    void insertAtFront(t);
    void insertAtEnd(t);
    t removeFromFront();
    void display();
};
template <class t>
void List<t>::insertAtFront(t data)
{
    if(sizeL<maxSize)
    {
        sizeL++;
        Node* newNode = new Node();
        newNode->item=data;
        if(start==nullptr)
        {
            newNode->next=nullptr;
            start=newNode;
        }
        else
        {
            newNode->next=start;
            start=newNode;
        }
    }
    else
    {
        throw OVERFLOW{};
    }

}
template<class t>
void List<t>::insertAtEnd(t _item)
{
    if(sizeL<maxSize)
    {
        sizeL++;
        Node* newNode = new Node();
        newNode->item = _item;
        newNode->next = nullptr;
        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            Node* p = start;
            Node* q = p->next;
                for(; q != nullptr ; p = q , q = p->next) ;
            p->next = newNode;
        }
    }
    else
    {
        cout<<"";
    }
}
template <class t>
t List<t>::removeFromFront()
{
    if(start==nullptr)
        throw UNDERFLOW();
    sizeL--;
    t temp=start->item;
    start=start->next;
    return temp;
}
template <class t>
void List<t>::display()
{
    if(start == nullptr)
        throw UNDERFLOW();
    Node* p = start;
    for(; p != nullptr ; p = p->next)
        std::cout<<" "<<p->item;
}

class Poly
{
    const int coefNum1;
    const int coefNum2;
public:
    List<float> p1;
    List<float> p2;
    Poly(int n1,int n2):coefNum1(n1),coefNum2(n2)
    {
        p1.setMax(coefNum1+1);
        p2.setMax(coefNum2+1);
    }
    void getInput();
    void displayP(List<float>);
    List<float> add(List<float> ,List <float> );
    void calc();
};
void Poly::displayP(List<float> _list)
{
    for(int i=_list.sizeG();i>0;i--)
    {
        cout<<_list.removeFromFront()<<"x^"<<i-1<<" + ";
    }
    cout<<"\b\b\b\b\b\b      \b\b\b\b\b\b";
}
void Poly::calc()
{
    List<float> res;
    res=add(p1,p2);
    cout<<"\t";
    displayP(res);
}
List<float> Poly::add(List<float> La,List <float> Lb)
{
    int diff;
    List<float> a=La;
    List<float> b=Lb;
    List<float> res;
    cout<<"\n--------------------------------ADDING--------------------------------\n\t";
    displayP(La);
    cout<<"\n\n+\t";
    displayP(Lb);
    cout<<"\n----------------------------------------------------------------------\n";
    if(coefNum1>=coefNum2)
    {
        diff=coefNum1-coefNum2;
        List<float> sum(coefNum1+1);
        for(int i=0;i<diff;i++)
        {
            sum.insertAtEnd(a.removeFromFront());
        }
        for(int i=0;i<=coefNum1-diff+1;i++)
        {
            try
            {
            float added=a.removeFromFront()+b.removeFromFront();
            sum.insertAtEnd(added);
            }
            catch(List<float>::UNDERFLOW)
            {
                cout<<"";
            }
        }
        res=sum;
    }
    else
    {
        diff=coefNum2-coefNum1;
        List<float> sum(coefNum2+1);
        for(int i=0;i<diff;i++)
        {
            sum.insertAtEnd(b.removeFromFront());
        }
        for(int i=0;i<=coefNum1-diff+1;i++)
        {
            float added=a.removeFromFront()+b.removeFromFront();
            sum.insertAtEnd(added);
        }
        res=sum;
    }
    return res;
}
void Poly::getInput()
{
    cout<<"Enter first Polynomial:\n";
    for(int i=0;i<=coefNum1;i++)
    {
        float num;
        cout<<"Coefficient of x^"<<i<<" :";
        cin>>num;
        p1.insertAtFront(num);
    }
    cout<<"Enter second Polynomial:\n";
    for(int i=0;i<=coefNum2;i++)
    {
        float num;
        cout<<"Coefficient of x^"<<i<<" :";
        cin>>num;
        p2.insertAtFront(num);
    }
}
int main()
{
    int deg1,deg2;
    List<float> l;
    cout<<"Enter Degree of Polynomial 1:";
    cin>>deg1;
    cout<<"Enter Degree of Polynomial 2:";
    cin>>deg2;
    Poly p(deg1,deg2);
    p.getInput();
    cout<<"\n\n";
    p.calc();
}

