#include<iostream>
using namespace std;
int snp(int*p,int ind)
{
    if(ind ==-1)
    {
        return 0;
    }
    int res;
    res=snp(p,ind -1);
    cout<<"enetr data=";
    cin>>*(p+ind);
    return res+*(p+ind);
}
int main()
{
    int arr[6];
    cout<<snp(arr,5);  
}