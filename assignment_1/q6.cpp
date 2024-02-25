#include<iostream>
using namespace std;
int isprime(int num,int i)
{
    if(num==i)
    {
        return 1;
    }
    if(num%i==0)
    {
        return 0;
    }
    return isprime(num,i+1);
}
int main()
{
    cout<<isprime(17,2);
}