#include<bits/stdc++.h>
using namespace std;

int precedence(char optr)
{
    if(optr=='^')
        return 3;
    else if(optr=='*' || optr=='/')
        return 2;
    else if (optr=='+' || optr=='-')
        return 1;
    else 
        return -1;
}

string infixToPostfix(string Expr)
{
    stack<char> st;
    string postExpr;
    int length=Expr.length();
    
    st.push('N');
    
    for(int i=0;i<length;i++)
    {
        if((Expr[i]>='a' && Expr[i]<='z') || (Expr[i]>='0' && Expr[i]<='9'))
        postExpr+=Expr[i];
        
        else if(Expr[i]==')')
        {
            while(st.top()!='(' && st.top()!='N')
            {
                    postExpr=postExpr+st.top();
                    st.pop();

            }
            if(st.top()=='(')
            {
                st.pop();
            }
                    
        }
        else if(Expr[i]=='(')      
        st.push('(');
        
        else if (Expr[i]=='+' || Expr[i]=='-' ||Expr[i]=='*' ||Expr[i]=='/' ||Expr[i]=='^')
        {
            if(precedence(Expr[i])>precedence(st.top()))
            st.push(Expr[i]);
            else
            {
            postExpr=postExpr+st.top();
            st.pop();
            st.push(Expr[i]);
            }
        }
    }
    while(st.top()!='N')
    {
        postExpr=postExpr+st.top();
            st.pop();
    }
    return postExpr;
}

string infixToPrefix(string Expr)
{
    reverse(Expr.begin(),Expr.end());
    for(int i=0;i<Expr.length();i++)
    {
        if (Expr[i] == '(') 
            Expr[i] = ')';
        
        else if (Expr[i] == ')') 
            Expr[i] = '(';
        
    }
    string revExpr = infixToPostfix(Expr);
    reverse(revExpr.begin(),revExpr.end());
    return revExpr;
}

int main()
{
    string Expr;
    cout<<"Enter infix expression:";
    cin>>Expr;
    cout<<"\nPostfix: "<<infixToPostfix(Expr)<<"\nPrefix: "<<infixToPrefix(Expr);
    return 0;
}
