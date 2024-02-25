#include<iostream>
#include<numeric>
using namespace std;
int isprime(int x)
{
    for(int i=2;i<x;i++){
        if(x%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int prime(int sum,int curval)
{
    if(isprime(curval))
    {
        return sum+1;
    }
    return sum;
}
int main()
{
    vector<int>v;
    int x;
    while(1)
    {
        cout<<"enter data= ";
        cin>>x;
        if(x==0)
        {
            break;
        }
        v.push_back(x);
    }
    int sum;
    sum=accumulate(v.begin(),v.end(),0,prime);
    cout<<sum;
}