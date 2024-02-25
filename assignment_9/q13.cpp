#include<iostream>
using namespace std;
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
    vector<int>::iterator itr;
    itr=v.begin();
    int min=v[0];
    int max=v[0];
    while(itr!=v.end())
    {
        min=min<*itr?min:*itr;
        max=max>*itr?max:*itr;
        itr++;
    }
    cout<<min<<" "<<max<<endl;
}