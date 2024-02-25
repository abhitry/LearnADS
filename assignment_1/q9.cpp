#include<iostream>
using namespace std;
int search(int *p,int ind,int x)
{
    if(ind ==-1)
    {
        return 0;
    }
    int res;
    res=search(p,ind-1,x);
    cout<<"enter array elements=";
    cin>>*(p+ind);
    if(*(p+ind)==x)
    {
        return 1;
    }
    return res;
}
int main()
{
    int n;
    cout<<"enetr length =";
    cin>>n;
    int *q=new int [n];
    cout<<search(q,n-1,1);
}