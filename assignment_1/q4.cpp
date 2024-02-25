#include<iostream>
using namespace std;
int  scan()
{
    int x;
    cout<<"enter x=";
    cin>>x;
    if(x==0)
    {
        return 0;
    }
    return scan()+x;
}
int main()
{
    cout<<scan();
}