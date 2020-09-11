#include <iostream>

using namespace std;

struct DATE
{
  private:
  int year;
  int month;
  int day;
  public:
  DATE(int a=2020,int b=8,int c=31)
  {
      year=a;
      month=b;
      day=c;
  }

friend int calcAge(DATE *,DATE *);

};

int calcAge(DATE * birthYear,DATE* currYear)
{
    int yr,mn,d;
        yr=currYear->year-birthYear->year;
        if(yr<0)
        return -1;
        if(birthYear->month>=currYear->month)
            yr--;
    return yr;

            
}

void showAge(int age)
{
    if(age==-1)
    {
        cout<<"\nInvalid dates entered.";
    }
    else
    {
        cout<<"\nYou are "<<age<<" years old.";
    }
}
int main()
{
    DATE D1(2000,2,16);
    DATE D2(2020,3,14);
    DATE D3(2005,7,23);
    int age;
    age=calcAge(&D1,&D2);
    showAge(age);
    showAge(calcAge(&D2,&D3));
    showAge(calcAge(&D3,&D2));
    
}