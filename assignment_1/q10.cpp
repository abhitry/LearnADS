#include<iostream>
using namespace std;
void copy(char*p,char*q)
{
    if(*p=='\0')
    {
        *q='\0';
        return ;
    }
    *q=*p;
    copy(p+1,q+1);
}
int main()
{
    char str1[30]="hi my name is abhi";
    char str2[30];
    copy(str1,str2);
    cout<<str2;
}