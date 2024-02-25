#include<iostream>
using namespace std;
int main()
{
    vector<vector<int> >vv;
    vector<int>v;
    int x;
    int sum=0;
    for(int i=0;i<3;i++)
    {
        sum=0;
        for(int j=0;j<4;j++)
        {
            cout<<"enter data=";
            cin>>x;
            v.push_back(x);
            sum=sum+x;
        }
        cout<<sum<<" ";
        vv.push_back(v);
        v.clear();
    }

}   