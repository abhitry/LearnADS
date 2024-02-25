#include<iostream>
#include<numeric>
#include<algorithm>
#include<vector>
using namespace std;
int even(int sum,int curval)
{
    if(curval%2==0)
    {
        return sum+1;
    }
    return sum;
}
int main()
{
    vector<int>v;
    int i;
    for(i=0;i<8;i++)
    {
        v.push_back(0);
    }
    for(i=0;i<8;i++)
    {
        cin>>v[i];
    }
    int sum;
    sum=accumulate(v.begin(),v.end(),0,even);
    cout<<sum;
}