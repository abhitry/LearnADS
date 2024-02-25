#include<iostream>
using namespace std;
void stcopy(char *p,char *q)
{
    if(*p=='\0')
    {
        *q='\0';
        return;
    }
    *q=*p;
    stcopy(p+1,q+1);
}
int main()
{
    char str1[30]="hello";
    char str2[30];
    stcopy(str1,str2);
    cout<<str2;
}