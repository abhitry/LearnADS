#include<iostream>
#include<numeric>
using namespace std;
int main()
{
    vector<int>v;
    int i;
    for(i=0;i<10;i++)
    {
        v.push_back(i);
    }
    int x;
    cout<<"enter x= ";
    cin>>x;
    for(i=0;i<10;i++)
    {
        if(v[i]%x==0)
        {
            cout<<v[i]<<" ";
        }
    }
}