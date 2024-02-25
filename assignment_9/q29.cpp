#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"enter number of rows= ";
    cin>>m;
    cout<<"enter number of colums= ";
    cin>>n;
    vector<vector<int> >vv(m,vector<int>(n,0));
    vector<vector<int> >::iterator itr=vv.begin();
    vector<int>::iterator subitr=(*itr).begin();
    int x;
    cout<<"enter number to be counted= ";
    cin>>x; 
    int cnt=0;
    while(itr!=vv.end())
    {
        subitr=(*itr).begin();
        while(subitr!=(*itr).end())
        {
            cout<<"enter data- ";
            cin>>*subitr;
            // if(*subitr==x)
            // {
            //     count++;
            // }
            subitr++;
        }
        itr++;
    }
    itr=vv.begin();
    // cout<<count;
    while(itr!=vv.end())
    {
        cnt=cnt+count((*itr).begin(),(*itr).end(),x);
        itr++;
    }
    cout<<cnt;
}