#include<iostream>
using namespace std;
void scan()
{
    char str[30];
    cout<<"enter string or STOP to stop= ";
    cin.getline(str,30);
    if(strcmp(str,"STOP")==0)
    {
        return;
    }
    cout<<strlen(str)<<endl;
    scan();
}
int main()
{
    scan();
}