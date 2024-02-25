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
    vector<int>::iterator itr;
    itr=v.begin();
    while(itr!=v.end())
    {
        sum=sum+*itr;
        itr++;
    }
    cout<<sum;
}