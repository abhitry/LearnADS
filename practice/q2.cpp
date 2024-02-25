#include<iostream>
#include<stack>
using namespace std;
int getpriority(char ch)
{
    if(ch=='+'|| ch=='-')
    {
        return 1;
    }
    if(ch=='/'|| ch=='*')
    {
        return 2;
    }
    if(ch=='^')
    {
        return 3;
    }
    return 0;
}
int main()
{
    char infix[30]={'a','+','b','*','c'};
    int i=0,j=4;
    char postfix[30];
    while(i<=j)
    {
        swap(infix[i],infix[j]);
        i++;
        j--;
    }
    for(i=0;i<5;i++)
    {
        if(infix[i]=='(')
        {
            infix[i]=')';
        }
        else if(infix[i]==')')
        {
            infix[i]='(';
        }
    }
    i=0;
    j=0;
    stack<char>stk;
    while(infix[i]!='\0')
    {
        char ch=infix[i];
        if(ch=='(')
        {
            stk.push('(');
        }
        else if (ch==')')
        {
            while(!stk.empty()&& stk.top()!='(')
            {
                postfix[j]=stk.top();j++;
                stk.pop();
            }
            stk.pop();
        }
        else if (ch=='-'|| ch=='+'|| ch=='/'|| ch=='*'||ch=='^')
        {
            char expop=ch;
            while(!stk.empty())
            {
                char stkop=stk.top();
                stk.pop();
                if(getpriority(stkop)>getpriority(expop))
                {
                    postfix[j]=stkop;j++;
                }
                else
                {
                    stk.push(stkop);
                    break;
                }
            }
            stk.push(expop);
        }
        else
        {
            postfix[j]=ch;
            j++;
        }
        i++;
    }  
    while(!stk.empty())
    {
        postfix[j]=stk.top();j++;
        stk.pop();
    } 
    postfix[j]='\0';
    for(i=0;i<5;i++)
    {
        cout<<postfix[i];
    }
}