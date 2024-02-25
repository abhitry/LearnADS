#include<iostream>
using namespace std;
int len(char*p)
{
    if(*p=='\0')
    {
        return 0;
    }
    return len(p+1)+1;
}
int main()
{
    char str[30]="hell00o";
    cout<<len(str);
}