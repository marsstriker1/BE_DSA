#include <bits/stdc++.h>
using namespace std;

bool checkParan(string expr)
{
    stack <char> st;
    st.push('T');
    for(int i=0;i<expr.length();i++)
    {
        if(expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
        st.push(expr[i]);
        else if(expr[i]==')')
        {
            if(st.top()!='T' && st.top()!='{' && st.top()!='[')
            st.pop();             
            else 
            return false;
        }
        else if(expr[i]=='}')
        {
            if(st.top()!='T' && st.top()!='(' && st.top()!='[')
            st.pop();             
            else 
            return false;
        }
        else if(expr[i]==']')
        {
            if(st.top()!='T' && st.top()!='(' && st.top()!='{')
            st.pop();             
            else 
            return false;
        }
        
    }
    if(st.top()=='T')
    return true;
    else
    return false;
}
int main()
{
    string str;
    cout<<"Enter expression:";
    cin>>str;
    if(checkParan(str))
    {
        cout<<"All paranthesis are paired";
    }
    else
    {
        cout<<"Unpaired paranthesis.";
    }
    return 0;
}
