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
    vector<int>::iterator max,min;
    max=max_element(v.begin(),v.end());
    min=min_element(v.begin(),v.end());
    cout<<*min<<" "<<*max<<endl;
}