#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>v(8);
    int x;
    for(int i=0;i<8;i++)
    {
        cout<<"enter data= ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"enter number to search= ";
    cin>>x;
    int count=0;
    vector<int>::iterator loc=v.begin();
    while(1)
    {
        loc=find(loc,v.end(),x);
        if(loc==v.end())
        {
            break;
        }
        cout<<*loc;
        count++;
        loc++;
    }
    cout<<endl<<count;
    // int cnt;
    // cnt=count(v.begin(),v.end(),x);
    // cout<<cnt;

}