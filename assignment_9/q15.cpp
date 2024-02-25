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
    vector<int>::iterator itr;
    itr=v.begin();
    while (itr!=v.end())
    {
        if(*itr==x)
        {
            cout<<"present";
            break;
        }
        itr++;
    }
    if(itr==v.end())
    {
        cout<<"not present ";
    }
    itr=v.begin();
    int count=0;
    while (itr!=v.end())
    {
        if(*itr==x)
        {
            count++;
        }
        itr++;
    }
    cout<<endl<<count;
}