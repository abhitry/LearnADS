#include<iostream>
using namespace std;
int main()
{
    int x;
    vector<int>v;
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
    for(int i=0;i<v.size();i++)
    {
        sum=sum+v[i];
    }
    cout<<sum;
}