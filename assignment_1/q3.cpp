#include<iostream>
using namespace std;
int add(int n)
{
    if(n==0)
    {
        return 0;
    }
    int res;
    res= add(n/10);
    return res+n%10;
}
int main()
{
    cout<<add(123);
}