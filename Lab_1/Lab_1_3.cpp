#include<bits/stdc++.h>
using namespace std;

float getRes(float a, float b, char op)
{
    switch(op)
            {
                case '+':
                    return b+a;
                case '-':
                    return b-a;
                case '*':
                    return b*a;
                case '/':
                    return b/a;
                default:
                {
                cout<<"error!";
                exit(0);
                }
            }
}
float evalPostfix(string expr)
{
    stack <char> st;
    float a,b;
    float res;
    for(int i=0;i<expr.length();i++)
    {
        if(expr[i]>='0' && expr[i]<='9')
        {
            st.push(expr[i]);
        }
        else if(expr[i]=='+' ||expr[i]=='-' ||expr[i]=='*' ||expr[i]=='/')
        {
            a=static_cast<float>(st.top()-48);
            st.pop();
            b=static_cast<float>(st.top()-48);
            st.pop();
            res=getRes(a,b,expr[i]);
            st.push(static_cast<char>(res+48));
        }
    }
    return static_cast<float>(st.top()-48);
}
int main()
{
    float a=0;
    char aa=static_cast<char>(49);
    //cout<<aa;
    cout<<evalPostfix("456*+");
}