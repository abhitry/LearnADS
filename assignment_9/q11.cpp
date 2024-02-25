#include<iostream>
#include<numeric>
using namespace std;
int isprime(int x)
{
    for(int i=2;i<x;i++)
    {
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int add(int sum,int x)
{
    if(isprime(x))
    {
        return sum+x;
    }
    return sum;
}
int main()
{
    vector<int>v;
    int x;
    while(1)
    {
        cout<<"enter number = ";
        cin>>x;
        if(x==0)
        {
            break;
        }
        v.push_back(x);
    }
    int sum=0;
    sum=accumulate(v.begin(),v.end(),0,add);
    cout<<sum;
}