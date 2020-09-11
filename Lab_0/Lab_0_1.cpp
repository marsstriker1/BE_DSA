#include <iostream>

using namespace std;

int strLeng(const char * str)
{
    int l=0;
    while(str[l]!='\0')
    {
        l++;
    }
    return l;
}
void concatStr(const char * str1,const char* str2)
{
    int l1 = strLeng(str1);
    int l2=strLeng(str2);
    char *res;
    res = new char[l1+l2];
    for(int i=0;i<=l1;i++)
    res[i]=str1[i];
    for(int i=0;i<=l2;i++)
    res[l1+i]=str2[i];
    cout<<res;
}
int main()
{
    concatStr("DATA","STRUCTURE");
    return 0;
}