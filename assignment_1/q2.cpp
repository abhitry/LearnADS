#include<iostream>
using namespace std;
int expo(int base,int pow)
{
    if(pow==0)
    {
        return 1;
    }
    return expo(base,pow-1)*base;
}
int main()
{
    int b,p;
    cout<<"enetr base and power=";
    cin>>b>>p;
    cout<<expo(b,p);
}   