#include<iostream>
#include<numeric>
using namespace std;
int add(int sum,int x)
{
    if(x%2==0)
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