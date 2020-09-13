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

string infixToPostfix(string Expr)//,bool post)
{
    stack<char> st;
    string postExpr;
    int length=Expr.length();
    
    st.push('N');
    
    for(int i=0;i<length;i++)
    {
        if(Expr[i]>='a' && Expr[i]<='z')
        postExpr+=Expr[i];
        
        else if(Expr[i]==')')
        {
            do
            {
                if(st.top()!='(')
                {
                    postExpr=postExpr+st.top();
                    st.pop();
                }
            }while(st.top()!='(' && st.top()!='N'); 
            if(st.top()=='(')// && post)
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
        if (Expr[i] == '(') {
            Expr[i] = ')';
            i++;
        }
        else if (Expr[i] == ')') {
            Expr[i] = '(';
            i++;
        }
    }
    string revExpr = infixToPostfix(Expr);//,false);
    reverse(revExpr.begin(),revExpr.end());
    return revExpr;
}

int main()
{
    string Expr =  "(a/b+c)-(d+e*f)";//(a-(b)/c)*(d/e-f)";
    cout<<"Postfix: "<<infixToPostfix(Expr)<<"\nPrefix: "<<infixToPrefix(Expr);
    return 0;
}