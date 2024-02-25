#include<iostream>
using namespace std;
int main()
{
    vector<int>v(8);
    for(int i=0;i<8;i++)
    {
        v.push_back(i);
    }
    int x;
    cout<<"enter number to search= ";
    cin>>x;
    int c;
    c=count(v.begin(),v.end(),x);
    cout<<c;
    bool res;
    res=binary_search(v.begin(),v.end(),x);
    if(res==0)
    {
        cout<<"not found ";
    }
    else{
        cout<<"found";
    }
}